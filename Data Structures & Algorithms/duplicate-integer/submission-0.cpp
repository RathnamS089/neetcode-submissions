class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &n:nums){
            mp[n]++;
        }
        for(auto &a:mp){
            if(a.second>1){
                return true;
                break;
            }
        }
        return false;
    }
};