class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        pair<int,int>p={intervals[0][0],intervals[0][1]};
        for(int i=1;i<n;i++){
            if(p.second>intervals[i][0]){
                cnt++;
                p.second=min(p.second,intervals[i][1]);
                cout<<p.second<<endl;
            }
            else p={intervals[i][0],intervals[i][1]};
        }
        return cnt;
    }
};
