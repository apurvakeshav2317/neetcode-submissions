class Solution {
public:
int solve(vector<int>v,int i,int n,vector<int>dp){
    if(i>=n) return 0;
    int a=1e6,b=1e6;
    if(dp[i+1]!=1e6) a=dp[i+1];
    else a=solve(v,i+1,n,dp);
    if(dp[i+2]!=1e6)  b=dp[i+2];
    b=solve(v,i+2,n,dp);
    return dp[i]=v[i]+min(a,b);
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,1e6),dp2(n+1,1e6);
        return min(solve(cost,0,cost.size(),dp),solve(cost,1,cost.size(),dp2));
    }
};
