class Solution {
public:
      void dfs(int i,vector<vector<int>>& adj,vector<bool> &visited){
        visited[i]=true;
         for(auto &p:adj[i]){
           if(!visited[p]){
              dfs(p,adj,visited);
           }
         }
      }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
         for(int i=0;i<edges.size();i++){
           int u=edges[i][0];
           int v=edges[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);
         }
         int component=0;
         for(int i=0;i<n;i++){
           if(!visited[i]){
              dfs(i,adj,visited);
              component+=1;
           }
         }
      return component;
    }
};
