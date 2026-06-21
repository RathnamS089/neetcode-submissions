class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> mp(n + 1);
        for(auto &a:times){
            int firstnode=a[0];
            mp[firstnode].push_back({a[1],a[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        heap.push({0,k});
        set<int> visit;
        int t=0;
        while(!heap.empty()){
           auto [dist,node]=heap.top();
           heap.pop();
           if(visit.count(node)){
             continue;
           }
           visit.insert(node);
           t=max(t,dist);
           for(auto &e:mp[node]){
              if(!visit.count(e.first)){
                heap.push({e.second+dist,e.first});
              }
           }
        }
        if(visit.size()==n){
            return t;
        }
        return -1;
    }
};
