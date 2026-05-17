class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,set<int>>mp;
        for(int i=0;i<n;i++) mp[nums[i]].insert(i);
        for(auto it:mp){
            if(mp.count(target-it.first)){
                int k=*(it.second).begin();
                it.second.erase(k);
                mp[it.first]=it.second;
                vector<int>ans= {k,*(mp[target-it.first]).begin()};
                sort(ans.begin(),ans.end());
                return ans;
            }
        }
        return {};
    }
};
