class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i:nums){
            if(pq.size()<k){
            pq.push(i);
            }
            else{
                pq.push(i);
                pq.pop();
            }
        }
    }
    int add(int val) {
        pq.push(val);
        while(pq.size()>k){
           pq.pop();
        }
        auto ans=pq.top();
        return ans;
    }
};
