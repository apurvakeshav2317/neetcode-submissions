class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,1),suf(n,1);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]*nums[i];
        for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]*nums[i];
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            //cout<<pre[i]<<" "<<suf[i]<<endl;
            int a=(i-1>=0)?pre[i-1]:1;
            int b=(i<n-1)?suf[i+1]:1;
            ans[i]=a*b;
        }
        return ans;
    }
};
