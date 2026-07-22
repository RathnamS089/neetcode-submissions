class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        vector<vector<int>> res(row+1,vector<int>(col+1,0));
        res[row-1][col]=1;
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                if(obstacleGrid[i][j]==1){
                    res[i][j]=0;
                }
                else{
                    res[i][j]=res[i+1][j]+res[i][j+1];
                }
            }
        }
        return res[0][0];
    }
};