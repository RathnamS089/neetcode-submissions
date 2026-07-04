class Solution {
public:
    bool dfs(int i,int j,string &s1, string &s2, string &s3,unordered_map<string,bool> &mp){
        string key=to_string(i)+","+to_string(j);
        if(i==s1.size()&&j==s2.size()){
            return true;
        }
        if(mp.count(key)){
            return mp[key];
        }
        bool ans=false;
        if(i<s1.size()&&s1[i]==s3[i+j]){
            ans=ans||dfs(i+1,j,s1,s2,s3,mp);
        }
        if(j<s2.size()&&s2[j]==s3[i+j]){
            ans=ans||dfs(i,j+1,s1,s2,s3,mp);
        }
        mp[key]=ans;
        return mp[key];
    }
    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<string,bool> mp;
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        return dfs(0,0,s1,s2,s3,mp);
    }
};
