class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> res;
        for(int i=0;i<position.size();i++){
            res.push_back({position[i],speed[i]});
        }
        sort(res.begin(),res.end());
        stack<double> s;
        for (int i = res.size() - 1; i >= 0; i--) {
          double t = (double)(target - res[i][0]) / res[i][1];
          s.push(t);
          if (s.size() >= 2) {
            double first = s.top();
            s.pop();
            double second = s.top();
             s.push(first);
        if (first <= second) {
            s.pop();
        }
    }
}
        return s.size();
    }
};
