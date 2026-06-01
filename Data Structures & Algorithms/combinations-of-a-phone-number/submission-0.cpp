class Solution {
public:
     vector<string> res;
     unordered_map<char,string> map={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
    void backtrack(int i,string cur,string digits){
        if(cur.size()==digits.size()){
            res.push_back(cur);
            return;
        }
        string letters=map[digits[i]];
        for(char c:letters){
            backtrack(i + 1, cur + c, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
           return {};
        }
        backtrack(0,"",digits);
        return res;
    }
};
