class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans;
        int maxFreq = 0;
        for (auto &e : mp) {
        if (e.second > maxFreq) {
        maxFreq = e.second;
        ans = e.first;
     }
}

return ans;
    }
};