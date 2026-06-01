class Solution {
public:
    vector<vector<int>> res;
    void dfs(int i,vector<int>&nums,int target,vector<int>&sub,int sum){
         if(sum==target){
            res.push_back(sub);
            return;
         }
         if(i>=nums.size()){
            return;
         }
         if(sum>target){
            return;
         }
         sub.push_back(nums[i]);
         dfs(i,nums,target,sub,sum+nums[i]);
         sub.pop_back();
         dfs(i+1,nums,target,sub,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
         vector<int> sub;
        dfs(0,nums,target,sub,0);
        return res;
    }
};
