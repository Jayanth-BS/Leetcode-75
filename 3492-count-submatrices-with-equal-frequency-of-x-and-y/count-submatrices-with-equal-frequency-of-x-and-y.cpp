class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid[0].size(),ans=0;
        vector<int> forx(n,0);
        vector<int> fory(n,0);
        for(int i=0;i<grid.size();i++){
            int x=0,y=0;
            for(int j=0;j<n;j++){
                if(grid[i][j] == 'X') x++;
                if(grid[i][j] == 'Y') y++;
                forx[j] += x;
                fory[j] += y;
                if(forx[j]>0 && forx[j] == fory[j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};