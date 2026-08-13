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
    bool static const compare(Interval& a,Interval& b){
        return a.start<=b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);

        int last_end=intervals[0].end;

        for(int i=1;i<intervals.size();i++){
            int curr_start=intervals[i].start;
            if(curr_start<last_end)return false;
            last_end=intervals[i].end;
        }

        return true;
    }
};
