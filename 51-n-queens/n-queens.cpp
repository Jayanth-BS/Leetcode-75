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
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n,vector<int> &leftrow,vector<int> &updiag,vector<int> &downdiag){
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row] == 0 && updiag[row+col] == 0 && downdiag[n-1 + col-row]==0){
                board[row][col] = 'Q';
                leftrow[row] = 1;
                updiag[row+col] = 1;
                downdiag[n-1 + col-row]=1;
                solve(col+1,board,ans,n, leftrow,updiag, downdiag);
               leftrow[row] = 0;
                updiag[row+col] = 0;
                downdiag[n-1 + col-row]=0;
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
        vector<int> leftrow(n,0);
        vector<int> updiag(2*n-1,0);
        vector<int> downdiag(2*n-1,0);
        solve(0,board,ans,n,leftrow,updiag,downdiag);
        return ans;
    }
};