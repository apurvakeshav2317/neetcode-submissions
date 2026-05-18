class Solution {
public:
    
    int lcs(string s1,string s2,int n,int m,vector<vector<int>>&dp){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int solve(string word1,string word2,int n,int m,vector<vector<int>>&dp){
        if(n<0) return m+1;
        if(m<0) return n+1;
        if(dp[n][m]!=-1) return dp[n][m];
        if(word1[n]!=word2[m]) return dp[n][m]=1+min(solve(word1,word2,n-1,m,dp),min(solve(word1,word2,n-1,m-1,dp),solve(word1,word2,n,m-1,dp)));
        else return dp[n][m]=solve(word1,word2,n-1,m-1,dp);
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //if(m>n) swap(word1,word2);
        //int k=lcs(word1,word2,n,m,dp);
        return solve(word1,word2,n-1,m-1,dp);

    }
};
