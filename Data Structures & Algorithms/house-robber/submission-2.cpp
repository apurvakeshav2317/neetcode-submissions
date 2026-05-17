class Solution {
public:
    int solve(vector<int>v,int n,vector<int>&dp){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=max(dp[n],max(solve(v,n-1,dp),v[n]+solve(v,n-2,dp)));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,nums.size()-1,dp);
    }
};
