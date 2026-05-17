class Solution {
public:
    unordered_map<string,int>mp;
    unordered_map<int,vector<string>>mp1;
    int cnt=0;
    string encode(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        for(int i=0;i<n;i++) ans+=(strs[i]);
        mp[ans]=cnt;
        mp1[cnt]=strs;
        cnt++;
        return ans;
    }

    vector<string> decode(string s) {
        if(!mp.count(s)) return {};
        int k=mp[s];
        return mp1[k];
    }
};
