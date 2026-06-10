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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        for(auto &p:intervals){
          start.push_back(p.start);
          end.push_back(p.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int res=0,count=0;
        int j=0;
        for(int i=0;i<intervals.size();){
           if(start[i]<end[j]){
              i+=1;
              count+=1;
           }
           else{
              j+=1;
              count-=1;
           }
           res=max(res,count);
        }
        return res;
    }
};
