class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        set<pair<vector<int>,int>>s;
        int cnt=0;
        unordered_map<int,vector<string>>mp;
        for(int i=0;i<n;i++){
            vector<int>temp(26,0);
            for(int j=0;j<strs[i].size();j++){
                temp[strs[i][j]-'a']++;
            }
            auto it=s.lower_bound({temp,-1});
            if(it!=s.end()){
                vector<int>r=(*it).first;
                if(r==temp){
                    mp[(*it).second].push_back(strs[i]);
                }
                else{
                    s.insert({temp,cnt});
                    mp[cnt].push_back(strs[i]);
                    cnt++;
                }
            }else{
                s.insert({temp,cnt});
                mp[cnt].push_back(strs[i]);
                cnt++;
            }
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
