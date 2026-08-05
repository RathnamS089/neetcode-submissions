class Solution {
public:
    void dfs(int node,vector<bool> &vis,vector<vector<int>>& isConnected){
        vis[node]=true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i]==1&&vis[i]==false){
                dfs(i,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,isConnected);
                count++;
            }
        }
        return count;
    }
};