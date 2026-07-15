class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        int time=0,fresh=0;
        queue<pair<int,int>> q;
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()&&fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                for(auto &d:dir){
                    int row=r+d[0];
                    int col=c+d[1];
                    if(row<0||row==grid.size()||col<0||col==grid[0].size()||grid[row][col]!=1){
                        continue;
                    }
                    grid[row][col]=2;
                    q.push({row,col});
                    fresh--;
                }
            }
             time++;
        }
        if(fresh==0){
            return time;
        }
        return -1;
    }
};
