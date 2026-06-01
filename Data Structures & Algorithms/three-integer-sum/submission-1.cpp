#include<algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            if(i>0&&a==nums[i-1]){
                continue;
            }
            int l=i+1;
            int h=nums.size()-1;
            while (l<h){
                int sum3=a+nums[l]+nums[h];
                if(sum3>0){
                    h=h-1;
                }
                else if(sum3<0){
                    l=l+1;
                }
                else{
                    res.push_back({a,nums[l],nums[h]});
                    l++;
                    h--;
                    while(l<h&&nums[l]==nums[l-1]){
                    l=l+1;
                }
                }
            }
        }
        return res;
    }
};
