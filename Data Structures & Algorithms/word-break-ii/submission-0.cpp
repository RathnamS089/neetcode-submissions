class Solution {
public:
    void backtrack(int i,vector<string> &cur,vector<vector<string>> &res,string &s, vector<string>& wordDict,set<string> &se){
        if(i==s.size()){
            res.push_back(cur);
            return;
        }
        for(int j=i;j<s.size();j++){
            string word=s.substr(i,j-i+1);
            if(se.count(word)){
                cur.push_back(word);
                backtrack(j+1,cur,res,s,wordDict,se);
                cur.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> se;
        for(string w:wordDict){
            se.insert(w);
        }
        vector<string> cur;
        vector<vector<string>> res;
        backtrack(0,cur,res,s,wordDict,se);
        vector<string> ans;
        string temp;
          for (auto &sentence : res) {
    string temp = "";

    for (int i = 0; i < sentence.size(); i++) {
        temp += sentence[i];
        if (i != sentence.size() - 1)
            temp += " ";
    }

      ans.push_back(temp);
}
     return ans;
    }
};