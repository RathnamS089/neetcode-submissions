class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int curmin=1,curmax=1;
        for(int i:nums){
            if(i==0){
                curmin=1;
                curmax=1;
                res = max(res, 0);
                continue;
            }
            int tmp=curmax*i;
            curmax=max({i*curmax,i*curmin,i});
            curmin=min({tmp,i*curmin,i});
            res=max(res,curmax);
        }
        return res;
    }
};
