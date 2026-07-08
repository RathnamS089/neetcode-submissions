class Solution {
public:
    int maxSubArray(vector<int>& nums) {
          int a=INT_MIN;
          int cursum=0;
          for(int i=0;i<nums.size();i++){
             if(cursum<0){
                cursum=0;
             }
             cursum+=nums[i];
             a=max(a,cursum);
          }
          return a;
    }
};
