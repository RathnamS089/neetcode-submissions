class Solution {
   public:
    string minWindow(string s, string t) {
        if (s == t) {
            return s;
        }
        if (s.size() < t.size()) {
            return "";
        }
        unordered_map<char, int> window;
        unordered_map<char, int> tfreq;
        for (char c : t) {
            tfreq[c]++;
        }
        int left = 0;
        int have = 0;
        int min_length=INT_MAX;
        int start=0;
        int need = tfreq.size() ;
        for (int right = 0; right < s.size(); right++) {
            window[s[right]]++;
            if(tfreq.count(s[right])&&window[s[right]]==tfreq[s[right]]){
                have++;
            }
            while (have == need) {
                int curlen = right - left + 1;
                if(curlen<min_length){
                    min_length=curlen;
                    start=left;
                }
                window[s[left]]--;
                if (tfreq.count(s[left]) && window[s[left]] < tfreq[s[left]]) {
                    have--;
                }
                left++;
            }
        }
        if(min_length==INT_MAX){
            return "";
        }
        return s.substr(start,min_length);
    }
};
