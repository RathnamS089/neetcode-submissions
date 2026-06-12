class Solution {
public:
    void dfs(int row,int col,set<pair<int,int>> &visit,int h,vector<vector<int>>& heights){
        if (row < 0 || col < 0 ||
            row >= heights.size() ||
            col >= heights[0].size() ||
            visit.count({row,col}) ||
            heights[row][col] < h)
           {
             return;
           }
        visit.insert({row,col});
        dfs(row+1,col,visit,heights[row][col],heights);
        dfs(row-1,col,visit,heights[row][col],heights);
        dfs(row,col+1,visit,heights[row][col],heights);
        dfs(row,col-1,visit,heights[row][col],heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows=heights.size(),cols=heights[0].size();
        set<pair<int,int>> Pacific;
        set<pair<int,int>> Atlantic;
        for(int j=0;j<cols;j++){
          dfs(0,j,Pacific,heights[0][j],heights);
          dfs(rows-1,j,Atlantic,heights[rows-1][j],heights);
        }
        for(int i=0;i<rows;i++){
           dfs(i,0,Pacific,heights[i][0],heights);
           dfs(i,cols-1,Atlantic,heights[i][cols-1],heights);
        }
        vector<vector<int>> res;
        for(int i=0;i<rows;i++){
          for(int j=0;j<cols;j++){
            if(Pacific.count({i,j})&&Atlantic.count({i,j})){
              res.push_back({i,j});
            }
          }
        }
        return res;
    }
};
