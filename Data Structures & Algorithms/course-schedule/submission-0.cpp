class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int,int> indegree;
        unordered_map<int,vector<int>> adj;
        for(auto p : prerequisites){
            int course = p[0];
            int prerequisite = p[1];
            indegree[course]++;
            adj[prerequisite].push_back(course);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        return count == numCourses;
    }
};