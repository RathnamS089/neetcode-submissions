class Solution {
public:
    unordered_map<int,vector<int>> mp;
    unordered_set<int> visited;
    unordered_set<int> cycle;
    vector<int> output;
    bool dfs(int course,unordered_set<int> &visited,unordered_set<int> &cycle
     ){
       if(cycle.count(course)){
        return false;
       }
       if(visited.count(course)){
         return true;
       }
       cycle.insert(course);
       for(int i:mp[course]){
          if(dfs(i,visited,cycle)==false){
            return false;
          }
       }
       cycle.erase(course);
       visited.insert(course);
       output.push_back(course);
       return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto p:prerequisites){
            int course=p[0];
            int preq=p[1];
            mp[preq].push_back(course);
        }
        for(int i=0;i<numCourses;i++){
            if(dfs(i,visited,cycle)==false){
               return {};
            }
        }
        reverse(output.begin(),output.end());
        return output;
    }
};
