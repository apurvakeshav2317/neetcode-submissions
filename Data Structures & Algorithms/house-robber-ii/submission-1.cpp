class Solution {
public:
    int solve(vector<int>v,int n,vector<int>&dp,int last){
        if(n<0) return 0;
        if(n==0 && last) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=max(dp[n],max(solve(v,n-1,dp,last),v[n]+solve(v,n-2,dp,last)));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int a=solve(nums,n-2,dp,0);
        dp=vector<int>(n+1,-1);
        int b=nums[n-1]+solve(nums,n-3,dp,1);
        return max(a,b);
    }
};