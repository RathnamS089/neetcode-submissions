class Solution {
public:
    int dfs(int i, bool buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size()) {
            return 0;
        }

        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }

        if (buy) {
            int buyToday = dfs(i + 1, false, prices, dp) - prices[i];
            int cooldown = dfs(i + 1, true, prices, dp);

            return dp[i][buy] = max(buyToday, cooldown);
        } else {
            int sellToday = dfs(i + 2, true, prices, dp) + prices[i];
            int hold = dfs(i + 1, false, prices, dp);

            return dp[i][buy] = max(sellToday, hold);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return dfs(0, true, prices, dp);
    }
};
