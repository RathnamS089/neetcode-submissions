class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()==1){
            result.push_back(nums);
            return result;
        }
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            nums.erase(nums.begin()+i);
            vector<vector<int>> perms=permute(nums);
            for(int j=0;j<perms.size();j++){
                perms[j].push_back(val);
                result.push_back(perms[j]);
            }
            nums.insert(nums.begin()+i,val);
        }
        return result;
    }
};
