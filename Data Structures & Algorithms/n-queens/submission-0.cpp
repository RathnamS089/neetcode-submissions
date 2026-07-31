class Solution {
public:
    void backtrack(int r,vector<vector<string>> &res, vector<string> &board,set<int> &cols,set<int> &posdia,set<int> &negdia,int n){
        if(r==board.size()){
            res.push_back(board);
            return ;
        }
        for(int c=0;c<n;c++){
            if(cols.count(c)||posdia.count(r+c)||negdia.count(r-c)){
                continue;
            }
            cols.insert(c);
            posdia.insert(r+c);
            negdia.insert(r-c);
            board[r][c]='Q';
            backtrack(r+1,res,board,cols,posdia,negdia,n);
            cols.erase(c);
            posdia.erase(r+c);
            negdia.erase(r-c);
            board[r][c]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));
        set<int> cols;
        set<int> posdia;
        set<int> negdia;
        backtrack(0,res,board,cols,posdia,negdia,n);
        return res;
    }
};
