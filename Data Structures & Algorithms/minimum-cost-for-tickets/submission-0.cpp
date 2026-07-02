class Solution {
public:
    int dfs(int i,vector<int>& days, vector<int>& costs,vector<int> &dp){
        if(i==days.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=costs[0]+dfs(i+1,days,costs,dp);
        int k=i;
        while(k<days.size()&&days[k]<7+days[i]){
            k++;
        }
        int seven=costs[1]+dfs(k,days,costs,dp);
        int j=i;
        while(j<days.size()&&days[j]<30+days[i]){
            j++;
        }
        int thirty=costs[2]+dfs(j,days,costs,dp);
        return dp[i]=min({one,seven,thirty});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        int a=dfs(0,days,costs,dp);
        return a;
    }
};