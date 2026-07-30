class Solution {
public:
    void backtrack(int i,vector<int> &cur,int target,vector<int>& candidates,vector<vector<int>> &res){
        if(target==0){
            res.push_back(cur);
            return;
        }
        if(target<=0){
            return;
        }
        int prev=-1;
        for(int pos=i;pos<candidates.size();pos++){
            if(prev==candidates[pos]){
                continue;
            }
            cur.push_back(candidates[pos]);
            backtrack(pos+1,cur,target-candidates[pos],candidates,res);
            cur.pop_back();
            prev=candidates[pos];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        backtrack(0,cur,target,candidates,res);
        return res;
    }
};
