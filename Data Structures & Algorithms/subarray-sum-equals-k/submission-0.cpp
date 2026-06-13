class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        int cursum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            int dif=cursum-k;
            if(mp.count(dif)){
                res+=mp[dif];
            }
            mp[cursum]++;
        }
        return res;
    }
};