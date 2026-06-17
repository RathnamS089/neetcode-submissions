class Solution {
public:
    int quickselect(int l,int r,vector<int>&nums,int k){
      int pivot=nums[r];
      int p=l;
      for(int i=l;i<r;i++){
         if(nums[i]<nums[r]){
             int t=nums[p];
             nums[p]=nums[i];
             nums[i]=t;
             p+=1;
         }
      }
      int temp=nums[p];
      nums[p]=nums[r];
      nums[r]=temp;
      if(k<p){
        return quickselect(l,p-1,nums,k);
      }
      else if(k>p){
         return quickselect(p+1,r,nums,k);
      }
      else{
         return nums[p];
      }
    }
    int findKthLargest(vector<int>& nums, int k) {
        k=nums.size()-k;
        return quickselect(0,nums.size()-1,nums,k);
    }
};
