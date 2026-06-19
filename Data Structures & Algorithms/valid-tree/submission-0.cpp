class Solution {
public:
    bool dfs(int node,int prev,set<int> &visit,vector<vector<int>> &adj){
        if(visit.count(node)){
            return false;
        }
        visit.insert(node);
        for(int i:adj[node]){
            if(i==prev){
                continue;
            }
            if(!dfs(i,node,visit,adj)){
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
       if(n==0){
         return true;
       }
       vector<vector<int>> adj(n);
       for(auto &e:edges){
          int first=e[0];
          int second=e[1];
          adj[first].push_back(second);
          adj[second].push_back(first);
       }
       set<int> visit;
       return (dfs(0,-1,visit,adj)&&n==visit.size());
    }
};
