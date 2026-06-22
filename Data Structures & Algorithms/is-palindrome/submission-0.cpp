class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for(char c : s){
            if(isalnum(c)){
               result += c;
            }
         }
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        int l=0,r=result.size()-1;
        while(l<=r){
            if(result[l]==result[r]){
                l+=1;
                r-=1;
            }
            else{
                return false;
                break;
            }
        }
        return true;
    }
};
