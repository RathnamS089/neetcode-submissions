class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        if(pattern.size()!=words.size()){
            return false;
        }
        unordered_map<char,string> chartostr;
        unordered_map<string,char> strtochar;
        for(int i=0;i<pattern.size();i++){
            if(chartostr.count(pattern[i])&&chartostr[pattern[i]]!=words[i]){
                return false;
            }
            if(strtochar.count(words[i])&&strtochar[words[i]]!=pattern[i]){
                return false;
            }
            chartostr[pattern[i]]=words[i];
            strtochar[words[i]]=pattern[i];
        }
        return true;
    }
};