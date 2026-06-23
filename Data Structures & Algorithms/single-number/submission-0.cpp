class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto &e:mp){
            if(e.second==1){
                return e.first;
            }
        }
        return 0;
    }
};
