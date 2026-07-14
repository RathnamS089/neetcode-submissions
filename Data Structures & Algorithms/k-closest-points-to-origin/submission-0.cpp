class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            int dist=pow(points[i][0],2)+pow(points[i][1],2);
            pq.push({dist,i});
        }
        while(k>0){
            auto [dist,id]=pq.top();
            res.push_back({points[id][0],points[id][1]});
            pq.pop();
            k--;
        }
        return res;
    }
};
