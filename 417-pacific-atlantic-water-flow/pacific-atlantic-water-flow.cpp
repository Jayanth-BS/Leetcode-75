class Solution {
public:
    void check(int i, int j,vector<vector<bool>> &vis, vector<int> &dr,vector<int> &dc,vector<vector<int>>& heights){
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr>=0 && nc>=0 && nr < heights.size() && nc<heights[0].size() && !vis[nr][nc] && heights[nr][nc]>=heights[i][j]){        
                check(nr,nc,vis,dr,dc,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         vector<vector<int>> ans;
        if(heights.size() == 0)
        return ans;
       
        int m = heights.size(),n=heights[0].size();
        vector<int> dr = {0,-1,0,1};
        vector<int> dc = {-1,0,1,0};
        vector<vector<bool>> pac(m,vector<bool>(n,0));
        vector<vector<bool>> atl(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            check(i,0,pac,dr,dc,heights);
            check(i,n-1,atl,dr,dc,heights);
        }
        for(int j=0;j<n;j++){
            check(0,j,pac,dr,dc,heights);
            check(m-1,j,atl,dr,dc,heights);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};