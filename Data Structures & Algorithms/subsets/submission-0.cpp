class Solution {
public:
    vector<vector<int>> res;
    void dfs(int i,vector<int>& nums,vector<int> &subset){
       if (i>=nums.size()){
          res.push_back(subset);
          return;
       }
       subset.push_back(nums[i]);
       dfs(i+1,nums,subset);
       subset.pop_back();
       dfs(i+1,nums,subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
       dfs(0,nums,subset);
       return res;
    }
};
