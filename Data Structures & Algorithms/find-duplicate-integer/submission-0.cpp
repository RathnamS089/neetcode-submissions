class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
         mp[nums[i]]++;
      }
      int a;
        for(auto &m:mp){
            if(m.second>=2){
               a=m.first;
            }
        }
        return a;
    }
};
