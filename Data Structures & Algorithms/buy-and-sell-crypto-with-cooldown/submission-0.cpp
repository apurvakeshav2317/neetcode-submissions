class Solution {
public:
    int solve(vector<int>prices,int n,bool buy,int i,vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int a=-1e9,b=-1e9;
        if(buy){
            a=max(solve(prices,n,buy,i+1,dp),prices[i]+solve(prices,n,!buy,i+2,dp));
        }else{
            b=max(solve(prices,n,buy,i+1,dp),-prices[i]+solve(prices,n,!buy,i+1,dp));
        }
        return dp[i][buy]=max(a,b);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(prices,n,false,0,dp);
    }
};
