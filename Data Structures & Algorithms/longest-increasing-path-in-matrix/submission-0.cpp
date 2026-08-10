class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(r<0||c<0||r>=matrix.size()||c>=matrix[0].size()){
            return 0;
        }
        if(dp[r][c]!=-1){
           return dp[r][c];
        }
        int ans=1;
        if(r+1<matrix.size()&&matrix[r+1][c]>matrix[r][c]){
           ans=max(ans,1+dfs(r+1,c,matrix,dp));
        }
        if(r-1>=0&&matrix[r-1][c]>matrix[r][c]){
            ans=max(ans,1+dfs(r-1,c,matrix,dp));
        }
        if(c+1<matrix[0].size()&&matrix[r][c+1]>matrix[r][c]){
            ans=max(ans,1+dfs(r,c+1,matrix,dp));
        }
        if(c-1>=0&&matrix[r][c-1]>matrix[r][c]){
            ans=max(ans,1+dfs(r,c-1,matrix,dp));
        }
        return dp[r][c]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               ans=max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }
};
