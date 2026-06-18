class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2){
            return false;
        }
        set<int> dp;
        dp.insert(0);
        int target=sum/2;
        for(int i=nums.size()-1;i>=0;i--){
            set<int>nextdp;
            for(int t:dp){
               nextdp.insert(t);
               nextdp.insert(t+nums[i]);
            }
            dp=nextdp;
        }
        if(dp.count(target)){
            return true;
        }
        else{
            return false;
        }
    }
};
