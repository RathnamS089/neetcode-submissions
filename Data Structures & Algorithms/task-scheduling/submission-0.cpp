class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(char c:tasks){
            mp[c]++;
        }
        priority_queue<int,vector<int>,less<int>> pq;
        for(auto &p:mp){
           pq.push(p.second);
        }
        queue<pair<int,int>> q;
        int time=0;
        while(!pq.empty()||!q.empty()){
            while(!q.empty()&&q.front().second<=time){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                auto val=pq.top();
                pq.pop();
               if(val-1>0){
                  q.push({val-1,time+n+1});
            }
        }
            time++;
        }
        return time;
    }
};
