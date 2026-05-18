class Solution {
public:
    int solve(vector<int>coins,int n,int amount,vector<vector<int>>&dp){
        if(n<0) return 0;
        
        if(amount<0) return 0;
        if(amount==0) return 1;
        if(dp[n][amount]!=-1) return dp[n][amount];
        return dp[n][amount]=solve(coins,n,amount-coins[n],dp)+solve(coins,n-1,amount,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(coins,n-1,amount,dp);
    }
};
