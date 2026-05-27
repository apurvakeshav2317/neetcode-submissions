#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int longestIncreasingPath(
        vector<vector<int>>& matrix
    ) {

        rows = matrix.size();
        cols = matrix[0].size();

        memo.assign(
            rows,
            vector<int>(cols, 0)
        );

        int longestPath = 0;

        // Try starting DFS from every cell
        for (int row = 0; row < rows; row++) {

            for (int col = 0; col < cols; col++) {

                longestPath = max(
                    longestPath,
                    dfs(row, col, matrix)
                );
            }
        }

        return longestPath;
    }

private:

    int rows;
    int cols;

    vector<vector<int>> memo;

    const vector<pair<int, int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    int dfs(
        int row,
        int col,
        const vector<vector<int>>& matrix
    ) {

        // Already computed
        if (memo[row][col] != 0) {
            return memo[row][col];
        }

        int bestPath = 1;

        for (const auto& [dx, dy] : directions) {

            int nextRow = row + dx;
            int nextCol = col + dy;

            if (!isValid(nextRow, nextCol)) {
                continue;
            }

            // Only move to strictly larger value
            if (matrix[nextRow][nextCol]
                > matrix[row][col]) {

                bestPath = max(
                    bestPath,
                    1 + dfs(
                        nextRow,
                        nextCol,
                        matrix
                    )
                );
            }
        }

        memo[row][col] = bestPath;

        return bestPath;
    }

    bool isValid(int row, int col) {

        return row >= 0
            && row < rows
            && col >= 0
            && col < cols;
    }
};