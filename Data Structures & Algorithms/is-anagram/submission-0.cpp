class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1,mp2;
        int n=s.length();
        if(s.length()!=t.length()) return false;
        for(int i=0;i<n;i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        if(mp1.size()!=mp2.size()) return false;
        for(auto it:mp1){
            if(it.second!=mp2[it.first]) return false;
        }
        return true;
    }
};
