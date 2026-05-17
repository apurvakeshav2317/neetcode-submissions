class Solution {
public:
    int solve(vector<int>v,int n,int mid,int h){
        int ans=0;
        for(int i=0;i<n;i++){
            if(v[i]<mid) ans++;
            else if(v[i]%mid==0) ans+=(v[i]/mid);
            else ans+=((v[i]/mid)+1);
        }
        //cout<<ans<<endl;
        if(ans<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1,high=1e9;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(piles,n,mid,h)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
