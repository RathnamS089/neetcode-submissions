class Solution {
public:
    int backtrack(int i,int curtotal,vector<int>& nums, int &target, unordered_map<string,int> &mp ){
        string key=to_string(i)+","+to_string(curtotal);
        if(i==nums.size()){
            if(curtotal==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(mp.count(key)){
            return mp[key];
        }
        mp[key]=backtrack(i+1,curtotal+nums[i],nums,target,mp)+backtrack(i+1,curtotal-nums[i],nums,target,mp);
        return mp[key];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int> mp;
        return backtrack(0,0,nums,target,mp);
    }
};
