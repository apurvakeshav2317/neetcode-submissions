/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        set<pair<int,int>>s;
        for(int i=0;i<n;i++) {
            if(s.count({intervals[i].start,intervals[i].end})) return false;
            s.insert({intervals[i].start,intervals[i].end});
            
        }
        int ans=0;
        while(!s.empty()){
            auto p=*(s.begin());
            s.erase(p);
            auto it=s.lower_bound({p.second,0});
            while(it!=s.end()){
                p=*it;
                s.erase(p);
                it=s.lower_bound({p.second,0});
            }
            ans++;
        }
        return ans<=1;
    }
};
