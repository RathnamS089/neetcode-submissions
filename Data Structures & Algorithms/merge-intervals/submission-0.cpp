#include<algorithm>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(auto it=intervals.begin()+1;it!=intervals.end();it++){
            if(res.back()[1]>=(*it)[0]){
                res.back()[1]=max(res.back()[1],(*it)[1]);
            }
            else{
                res.push_back(*it);
            }
        }
        return res;
    }
};
