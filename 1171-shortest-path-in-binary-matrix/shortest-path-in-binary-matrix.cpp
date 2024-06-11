class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> steps(n,vector<int>(m,INT_MAX));
        
        if(grid[0][0] == 0 && grid[n-1][m-1] == 0)
        q.push({0,{0,0}});

        int dr[8] = {-1,-1,0,1,1,1,0,-1};
        int dc[8] = {0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            auto it = q.front();
            int step = it.first;
            int x = it.second.first;
            int y = it.second.second;
            q.pop();
            if(x == n-1 && y == m-1) return step+1;
            for(int i=0;i<8;i++){
                int nr = x+dr[i];
                int nc = y+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 0){
                    if(step+1 < steps[nr][nc]){
                        steps[nr][nc] =  step+1 ;
                        q.push({step+1,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};