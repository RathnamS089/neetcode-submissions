class Solution {
public:
    set<pair<int,int>> visited;
    bool res;
    bool dfs(int r,int c,int i,vector<vector<char>>& board, const string& word){
        int row=board.size();
        int col=board[0].size();
        if (i==word.size()){
          return true;
        }
        if(r<0||c<0||r>=row||c>=col||word[i]!=board[r][c]||visited.count({r,c})){
            return false;
        }
        if(word[i]==board[r][c]){
            visited.insert({r,c});
        }
        res=dfs(r+1,c,i+1,board,word)||dfs(r-1,c,i+1,board,word)||dfs(r,c+1,i+1,board,word)||dfs(r,c-1,i+1,board,word);
        visited.erase({r,c});
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dfs(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
