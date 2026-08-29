class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>,less<int>> pq;
        for(int i:stones){
            pq.push(i);
        }
        while(pq.size()>1){
            auto first=pq.top();
            pq.pop();
            auto second=pq.top();
            pq.pop();
            if(first==second){
                continue;
            }
            if(first!=second){
               pq.push(first-second);
            }
        }
        if(pq.size()==1){
            return pq.top();
        }
        return 0;
    }
};
