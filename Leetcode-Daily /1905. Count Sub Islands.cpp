// Question:
// You have two binary matrices, grid1 and grid2, both with dimensions m x n. Each matrix represents land (1) and water (0). An island consists of connected land cells in the four cardinal directions.
// Any cells beyond the grid are considered water.
// In grid2, an island is classified as a sub-island if all its cells are part of an island in grid1.
// Your task is to count the number of islands in grid2 that qualify as sub-islands.

//Intuition:
//do dfs on grid 2 and have a global variable to say if grid1[i][j] is one or not to say that the island in grid 2 is a subisland

// link:
//   https://leetcode.com/problems/count-sub-islands/description/

// Solution:
class Solution {
public:
    int x=0;
    void dfs(int i,int j,  vector<vector<int>> &dp,vector<vector<int>>& grid1,vector<vector<int>>& grid2)
    {
        if(grid1[i][j]!=1)
        x=1;
        
        if(!dp[i][j])
        dp[i][j] = 1;
        else
        return ;
        int m[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++){
            int nr = i+m[k][0], nc = j+m[k][1];
            if(nr>=0 && nr<grid2.size() && nc>=0 && nc<grid2[i].size() && grid2[nr][nc] == 1){
                dfs(nr,nc,dp,grid1,grid2);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
       int u=0;
        vector<vector<int>> dp(grid1.size(),vector<int>(grid1[0].size(),0));
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[0].size();j++){
                
                if(grid2[i][j]==1 && !dp[i][j]){
                    cout<<u<<' ';
                    dfs(i,j,dp, grid1, grid2);
                    if(x==0)
                    u++
                    x=0;
                }
            }
        }
        return u;
    }
};
