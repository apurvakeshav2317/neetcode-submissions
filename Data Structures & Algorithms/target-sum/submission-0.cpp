#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:

    int findTargetSumWays(
        vector<int>& nums,
        int target
    ) {

        int totalSum =
            accumulate(nums.begin(), nums.end(), 0);

        /*
         Impossible cases:

         1. Target magnitude exceeds total sum
         2. Required subset sum becomes non-integer
        */
        if (abs(target) > totalSum ||
            (target + totalSum) % 2 != 0) {

            return 0;
        }

        int requiredSum =
            (target + totalSum) / 2;

        /*
         dp[s] =
         number of ways to form sum s
        */
        vector<int> dp(requiredSum + 1, 0);

        dp[0] = 1;

        for (int num : nums) {

            /*
             Traverse backward to avoid
             reusing same element multiple times.
            */
            for (int sum = requiredSum;
                 sum >= num;
                 sum--) {

                dp[sum] += dp[sum - num];
            }
        }

        return dp[requiredSum];
    }
};