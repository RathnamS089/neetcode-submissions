class Solution {
public:
    int dfs(int n,unordered_map<int,int> &mp){
        if(mp.count(n)){
            return mp[n];
        }
        int res=0;
        for(int i=1;i<n;i++){
            int val=max(i,dfs(i,mp))*max(n-i,dfs(n-i,mp));
            res=max(res,val);
        }
        return mp[n]=res;
    }
    int integerBreak(int n) {
        unordered_map<int,int> mp;
        return dfs(n,mp);
    }
};