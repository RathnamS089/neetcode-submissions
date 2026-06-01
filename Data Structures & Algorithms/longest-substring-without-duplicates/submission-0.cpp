class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> s1;
        int l=0;
        int res=0;
        for(int i=0;i<s.size();i++){
              while(s1.count(s[i])){
               s1.erase(s[l]);
               l+=1;
            }
            s1.insert(s[i]);
            res=max(res,i-l+1);
        }
        return res;
    }
};
