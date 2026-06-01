class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> &perm,vector<int> &nums,unordered_map<int,int> &count){
         if(perm.size()==nums.size()){
            res.push_back(perm);
            return;
         }
         for(auto &p:count){
            int num=p.first;
            if(p.second>0){
                perm.push_back(num);
                p.second--;
                dfs(perm,nums,count);
                p.second++;
                perm.pop_back();
            }
         }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> count;
        vector<int>perm;
        for(int num:nums){
            count[num]++;
        }
        dfs(perm,nums,count);
        return res;
    }
};