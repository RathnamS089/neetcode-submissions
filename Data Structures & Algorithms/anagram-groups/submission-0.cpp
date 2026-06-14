class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> mp;
       vector<vector<string>> res;
       for(auto &s:strs){
         string s1=s;
         sort(s.begin(),s.end());
         mp[s].push_back(s1);
       }
       for(auto &m:mp){
        res.push_back(m.second);
       }
       return res;
    }
};
