class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        for(int i=0;i<=nums.size()-4;i++){
            int a=nums[i];
            if(i>0&&a==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<=nums.size()-3;j++){
               if(j>i+1&&nums[j]==nums[j-1]){
                 continue;
               }
               int l=j+1;
               int r=nums.size()-1;
               while(l<r){
                 long long sum = 1LL * a + nums[j] + nums[l] + nums[r];
                 if(sum>target){
                    r=r-1;
                 }
                 else if(sum<target){
                    l+=1;
                 }
                 else{
                    res.push_back({a,nums[j],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]){
                        l++;
                    }
                    while(l < r && nums[r] == nums[r+1]){
                        r--;
                    }
                 }
               }
            }
        }
        return res;
    }
};