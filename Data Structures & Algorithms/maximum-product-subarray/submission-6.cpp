class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=0;
        if(nums.size()==1){
            return nums[0];
        }
        for(int i=0;i<nums.size();i++){
            int prod=1;
            for(int j=i;j<nums.size();j++){
               prod*=nums[j];
               ans=max(ans,prod);
            }
        }
        return ans;
    }
};
