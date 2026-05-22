class Solution {
public:
    unordered_map<int,int> solve(int src,int n,unordered_map<int,set<pair<int,int>>>mp){
        unordered_map<int,int>dist;
        for(int i=0;i<n;i++) dist[i]=1e9;
        dist[src]=0;
        set<pair<int,int>>s;
        s.insert({0,src});
        while(!s.empty()){
            auto p=*s.begin();
            s.erase(p);
            int d=p.first;
            int child=p.second;
            for(auto it:mp[child]){
                if(it.second+d<dist[it.first]){
                    int dest=it.first;
                    auto f=s.find({dist[dest],dest});
                    if(f!=s.end()) s.erase(f);
                    dist[dest]=it.second+d;
                    s.insert({dist[dest],dest});
                }
            }
        }
        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,set<pair<int,int>>>mp;
        unordered_map<int,int>t;
        int m=times.size();
        for(int i=0;i<m;i++){
            mp[times[i][0]-1].insert({times[i][1]-1,times[i][2]});
        }
        t=solve(k-1,n,mp);
        int ans=-1;
        for(auto it:t){
            if(it.second!=1e9) ans=max(ans,it.second);
            else return -1;
        }
        return ans;
    }
};
