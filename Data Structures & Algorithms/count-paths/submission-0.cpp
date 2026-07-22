class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m+1,vector<int>(n+1,0));
        res[m-1][n]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                res[i][j]=res[i+1][j]+res[i][j+1];
            }
        }
        return res[0][0];
    }
};
