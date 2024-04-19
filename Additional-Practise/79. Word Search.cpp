// link :https://leetcode.com/problems/word-search/

// Question:
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

//Solution:
class Solution {
public:
    bool dfs(int l,string word,vector<vector<char>>& board,int i, int j,int m[4][2]){
       if(word[l] != board[i][j]){
        return 0;
        }

        if(word.size()-1 == l)
        return 1;

            char temp = board[i][j];
            board[i][j] ='$';
            for(int k=0;k<4;k++){
                int nr = i+m[k][0], nc = j+m[k][1];
                if(nr>=0 && nr<board.size() && nc>=0 && nc<board[i].size() && board[nr][nc]!='$'){
                     if(dfs(l+1,word,board,nr,nc,m))
                     return 1;
                }
            }        
            board[i][j] =temp;
        
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == word[0] && dfs(0,word, board, i,j,m)){
                    return 1;
                }
            }
        }
        return 0;
    }
};
