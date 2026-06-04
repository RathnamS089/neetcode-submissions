class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        int prod=1;
        for(int i=0;i<nums.size();i++){
            prod=prod*nums[i];
            prefix[i]=prod;
        }
        vector<int> postfix(nums.size());
        int p=1;
        for(int i=nums.size()-1;i>=0;i--){
            p=p*nums[i];
            postfix[i]=p;
        }
        vector<int> output;
        for(int i=0;i<nums.size();i++){
            int left;
            int right;
            if(i>0){
               left=prefix[i-1];
            }
            else{
                left=1;
            }
            if(i<nums.size()-1){
                right=postfix[i+1];
            }
            else{
                right=1;
            }
            output.push_back(left*right);
        }
        return output;
    }
};
