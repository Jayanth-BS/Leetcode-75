class Solution {
public:
    bool isSafe(vector<string> &board, int row,int col){
        int drow = row;
        int dcol = col;

        while(row >= 0 && col >=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = drow;
        col = dcol;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = drow;
        col = dcol;
        while(row < board.size() && col >=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] ='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i] = s;
        solve(0,board,ans,n);
        return ans;
    }
};