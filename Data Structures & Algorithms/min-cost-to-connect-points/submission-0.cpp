class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        set<int> s;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int ans=0;
        while(s.size()<n){
           auto [cost,node]=pq.top();
           pq.pop();
           if(s.count(node)){
            continue;
           }
           s.insert(node);
           ans+=cost;
           for(int nei=0;nei<n;nei++){
              if(!s.count(nei)){
                 int dist=abs(points[node][0]-points[nei][0])+abs(points[node][1]-points[nei][1]);
                 pq.push({dist,nei});
              }
           }
        }
        if(s.size()==n){
            return ans;
        }
        return -1;
    }
};
