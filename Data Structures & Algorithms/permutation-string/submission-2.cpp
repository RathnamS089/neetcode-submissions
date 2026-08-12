class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(char c:s1){
            mp1[c]++;
        }
        int left=0;
        for(int right=0;right<s2.size();right++){
            mp2[s2[right]]++;
            if(right-left+1>s1.size()){
                mp2[s2[left]]--;
                if(mp2[s2[left]] == 0){
                    mp2.erase(s2[left]);
                }
                left++;
            }
            if(mp1==mp2){
                return true;
            }
        }
        return false;
    }
};
