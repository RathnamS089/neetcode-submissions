class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]=i;
        }
        vector<int> res(nums1.size(),-1);
        stack<int> s;
        for(int i:nums2){
            int cur=i;
            while(!s.empty()&&cur>s.top()){
                int val=s.top();
                s.pop();
                int idx=mp[val];
                res[idx]=cur;
            }
            if(mp.count(cur)){
                s.push(cur);
            }
        }
        return res;
    }
};