class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        int resLen=0;
        bool hasodd=false;
        for(auto &c:freq){
            int f=c.second;
            if(f%2==0){
                resLen+=f;
            }
            else{
                hasodd=true;
                resLen+=f-1;
            }
        }
        if(hasodd){
            return resLen+1;
        }
        return resLen;
    }
};