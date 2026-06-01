class Solution {
public:
    set<pair<int,int>> visited;
    void bfs(int row, int col, vector<vector<char>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        visited.insert({row,col});
        int delRow[] = {-1,1,0,0};
        int delCol[] = {0,0,-1,1};
        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();
            int r = front.first;
            int c = front.second;
            for(int i=0;i<4;i++){
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];
                if(newRow>=0 && newRow<rows &&
                   newCol>=0 && newCol<cols &&
                   grid[newRow][newCol]=='1' &&
                   visited.find({newRow,newCol})==visited.end()){
                    q.push({newRow,newCol});
                    visited.insert({newRow,newCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()){
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        int island = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' &&
                   visited.find({i,j})==visited.end()){
                    bfs(i,j,grid);
                    island++;
                }
            }
        }
        return island;
    }
};
