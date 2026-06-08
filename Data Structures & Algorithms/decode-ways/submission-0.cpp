class Solution {
public:
    vector<int> dp;
    int dfs(int i,string &s){
       if(i==s.size()){
         return 1;
       }
       if(s[i]=='0'){
         return 0;
       }
       if(dp[i] != -1){
         return dp[i];
       }
       int res=dfs(i+1,s);
       if((i+1<s.size())&&((s[i]=='1')||(s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))){
           res+=dfs(i+2,s);
       }
       dp[i]=res;
       return res;
    }
    int numDecodings(string s) {
        dp.assign(s.size(),-1);
        return dfs(0,s);
    }
};
