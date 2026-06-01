class Solution {
public:
    string longestPalindrome(string s) {
        string res="";  
        int len=s.length();
        int reslen=0;
        for(int i=0;i<len;i++){
            int l=i;
            int r=i;
            for(;l>=0&&r<len&&s[l]==s[r];){
               if(r-l+1>reslen){
                  res=s.substr(l,r-l+1);
                  reslen=r-l+1;
               }
               l--;
               r++;
            }
            int l2=i;
            int r2=i+1;
            for(;l2>=0&&r2<len&&s[l2]==s[r2];){
                if(r2-l2+1>reslen){
                    res=s.substr(l2,r2-l2+1);
                    reslen=r2-l2+1;
                }
                l2--;
                r2++;
            }
        }
     return res;
    }
};
