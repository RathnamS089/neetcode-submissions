class Solution {
public:
    vector<vector<string>> res;
    vector<string> par;
    bool ispal(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l+=1;
            r-=1;
        }
        return true;
    }
    void dfs(string s,int i){
        if(i>=s.size()){
            res.push_back(par);
            return;
        }
        for(int j=i;j<=s.size()-1;j++){
           if(ispal(s,i,j)){
              par.push_back(s.substr(i,j+1-i));
              dfs(s,j+1);
              par.pop_back();
           }
        }
    }
    vector<vector<string>> partition(string s) {
       dfs(s,0);
       return res;
    }
};
