class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int m=INT_MAX;
       for(int i=0;i<nums.size();i++){
        int s=0;
         for(int j=i;j<nums.size();j++){
            s+=nums[j];
            if(s>=target){
                m=min(m,j-i+1);
            }
         }
       }
       return m == INT_MAX ? 0 : m;
    }
};