class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> s;
        int n=heights.size();
        int maxarea=0;
        for(int i=0;i<heights.size();i++){
            int start=i;
            while(!s.empty()&&s.top().second>heights[i]){
                auto [id,height]=s.top();
                s.pop();
                maxarea=max(maxarea,height*(i-id));
                start=id;
            }
            s.push({start,heights[i]});
        }
        while(!s.empty()){
            auto [id,h]=s.top();
            maxarea=max(maxarea,(h*(n-id)));
            s.pop();
        }
        return maxarea;
    }
};
