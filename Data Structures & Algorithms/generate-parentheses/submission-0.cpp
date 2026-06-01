class Solution {
public:
   vector<string> res;
    int n;
   void backtrack(int open,int close,string s){
            if(open==n&&close==n&&open==close){
               res.push_back(s);
               return;
            }
            if(open<n){
                backtrack(open+1,close,s+"(");
            }
            if(close<open){
                backtrack(open,close+1,s+")");
            }
        }
 vector<string> generateParenthesis(int n) {
        this->n=n;
        backtrack(0,0,"");
        return res;
    }
};
