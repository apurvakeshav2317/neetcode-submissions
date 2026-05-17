class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int>v(10001,1e9);
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int a=intervals[i][0],b=intervals[i][1];
            a--,b--;
            int len=b-a+1;
            for(int j=a;j<=b;j++){
                v[j]=min(v[j],len);
            }
        }
        int m=queries.size();
        vector<int>ans(m,-1);
        for(int i=0;i<m;i++){
            int c=queries[i];
            c--;
            if(v[c]!=1e9) ans[i]=v[c];
        }
        return ans;
    }
};
