class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            unordered_set<char> row;
            unordered_set<char> col;
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    if(row.count(board[i][j])){
                        return false;
                    }
                    row.insert(board[i][j]);
                }
                if(board[j][i]!='.'){
                    if(col.count(board[j][i])){
                        return false;
                    }
                    col.insert(board[j][i]);
                }
            }
        }
        for(int r=0;r<board.size();r+=3){
            for(int c=0;c<board[0].size();c+=3){
                 unordered_set<char> box;
                 for(int i=r;i<r+3;i++){
                    for(int j=c;j<c+3;j++){
                        if(board[i][j]!='.'){
                            if(box.count(board[i][j])){
                                return false;
                            }
                            box.insert(board[i][j]);
                        }
                    }
                 }
            }
        }
        return true;
    }
};
