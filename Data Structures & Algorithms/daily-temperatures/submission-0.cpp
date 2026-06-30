class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<pair<int,int>> m;
        for(int i=0;i<temperatures.size();i++){
            while(!m.empty()&&m.top().first<temperatures[i]){
                auto[temp,id]=m.top();
                m.pop();
                res[id]=i-id;
            }
            m.push({temperatures[i],i});
        }
        return res;
    }
};
