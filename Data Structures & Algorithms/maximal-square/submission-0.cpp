class Solution {
public:
    int rows, cols;
    vector<vector<int>> dp;
    int helper(vector<vector<char>>& matrix, int r, int c) {
        if (r >= rows || c >= cols)
            return 0;
        if (dp[r][c] != -1)
            return dp[r][c];
        int right = helper(matrix, r, c + 1);
        int down = helper(matrix, r + 1, c);
        int diag = helper(matrix, r + 1, c + 1);
        if (matrix[r][c] == '1') {
            dp[r][c] = 1 + min({right, down, diag});
        } else {
            dp[r][c] = 0;
        }
        return dp[r][c];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        dp.assign(rows, vector<int>(cols, -1));
        int maxSide = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                maxSide = max(maxSide, helper(matrix, r, c));
            }
        }
        return maxSide * maxSide;
    }
};