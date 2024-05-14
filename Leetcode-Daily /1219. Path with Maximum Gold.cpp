// In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

// Return the maximum amount of gold you can collect under the conditions:

class Solution {
public:
    int mx = INT_MIN;
    int find(int m,int n,vector<vector<int>> &grid,int sum,vector<vector<int>> &vis, int dr[],int dc[]){
        vis[m][n] = 1;
        sum += grid[m][n];
        mx = max(mx,sum);
        for(int i=0;i<4;i++){
            int nr = m + dr[i];
            int nc = n + dc[i];
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc] !=0 && !vis[nr][nc]){
                find(nr,nc,grid,sum,vis,dr,dc);
            }
        } 
        vis[m][n] = 0;
        return mx;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int sum = 0;
        int dc[4] = {0,1,0,-1};
        int dr[4] = {-1,0,1,0};
        int k=0;
        for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]>0){
                    vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),0));
                    k = find(i,j,grid,sum,vis,dr,dc);
                    cout<<k<<'\n';
                }
            }
        }
        return k;
    }
};
