class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto &n:nums){
           mp[n]++;
        }
        vector<pair<int,int>> res;
        for(auto &m:mp){
            res.push_back({m.second,m.first});
        }
        sort(res.begin(),res.end(),greater<pair<int,int>>());
        for(int i=0;i<k;i++){
            ans.push_back(res[i].second);
        }
        return ans;
    }
};
