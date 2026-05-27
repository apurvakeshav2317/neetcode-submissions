#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    bool isInterleave(
        string s1,
        string s2,
        string s3
    ) {

        int n = s1.length();
        int m = s2.length();

        // Length mismatch makes interleaving impossible
        if (n + m != s3.length()) {
            return false;
        }

        /*
         memo[i][j] stores:
         -1 -> unvisited
          0 -> false
          1 -> true
        */
        vector<vector<int>> memo(
            n + 1,
            vector<int>(m + 1, -1)
        );

        return dfs(
            0,
            0,
            s1,
            s2,
            s3,
            memo
        );
    }

private:

    bool dfs(
        int i,
        int j,
        const string& s1,
        const string& s2,
        const string& s3,
        vector<vector<int>>& memo
    ) {

        // All characters consumed successfully
        if (i == s1.length() &&
            j == s2.length()) {

            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int k = i + j;

        bool canForm = false;

        /*
         Try taking next character from s1
        */
        if (i < s1.length() &&
            s1[i] == s3[k]) {

            canForm = dfs(
                i + 1,
                j,
                s1,
                s2,
                s3,
                memo
            );
        }

        /*
         Only try s2 path if needed.
         Avoids unnecessary recursion.
        */
        if (!canForm &&
            j < s2.length() &&
            s2[j] == s3[k]) {

            canForm = dfs(
                i,
                j + 1,
                s1,
                s2,
                s3,
                memo
            );
        }

        memo[i][j] = canForm;

        return canForm;
    }
};