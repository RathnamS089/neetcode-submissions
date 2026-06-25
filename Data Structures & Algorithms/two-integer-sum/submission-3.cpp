class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int diff=target-nums[i];
            if(mp.count(diff)){
                res[0]=mp[diff];
                res[1]=i;
            }
            mp[nums[i]]=i;
        }
        return res;
    }
};
