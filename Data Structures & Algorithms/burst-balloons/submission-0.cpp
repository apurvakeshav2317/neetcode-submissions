#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {

        // Add virtual boundaries
        vector<int> balloons;
        balloons.push_back(1);

        for (int value : nums) {
            balloons.push_back(value);
        }

        balloons.push_back(1);

        const int n = balloons.size();

        // dp[left][right]
        // max coins from interval (left, right)
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // interval length
        for (int length = 2; length < n; ++length) {

            for (int left = 0; left + length < n; ++left) {

                int right = left + length;

                // choose last balloon to burst
                for (int last = left + 1; last < right; ++last) {

                    int currentCoins =
                        dp[left][last] +
                        dp[last][right] +
                        balloons[left] *
                        balloons[last] *
                        balloons[right];

                    dp[left][right] =
                        max(dp[left][right], currentCoins);
                }
            }
        }

        return dp[0][n - 1];
    }
};