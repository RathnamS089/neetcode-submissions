class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> nums1(nums);
        vector<int> nums2(nums);
        nums1.pop_back();
        nums2.erase(nums2.begin());
        int rob1=0,rob2=0,rob3=0,rob4=0;
        for(int i=0;i<nums1.size();i++){
            int temp=max(nums1[i]+rob1,rob2);
            rob1=rob2;
            rob2=temp;
        }
        for(int i=0;i<nums2.size();i++){
            int t=max(nums2[i]+rob3,rob4);
            rob3=rob4;
            rob4=t;
        }
        return max(rob2,rob4);
    }
};
