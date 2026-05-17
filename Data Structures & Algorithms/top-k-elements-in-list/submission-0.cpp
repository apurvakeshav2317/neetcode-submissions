class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        set<pair<int,int>>s;
        for(int i=0;i<n;i++){
            auto it=s.lower_bound({nums[i],-1});
            if(it!=s.end()){
                auto p=*it;
                if(p.first==nums[i]){
                    s.erase(p);
                    s.insert({p.first,p.second+1});
                }else s.insert({nums[i],1});
            }
            else s.insert({nums[i],1});
        }
        set<pair<int,int>>st;
        for(auto i:s){
            st.insert({i.second,i.first});
            if(st.size()>k) st.erase(st.begin());
        }
        vector<int>ans(k,0);
        int cnt=0;
        for(auto i:st){
            ans[cnt]=i.second;
            cnt++;
        }
        return ans;
    }
};
