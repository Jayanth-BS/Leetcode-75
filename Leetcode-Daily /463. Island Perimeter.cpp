// Question:
// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.

// Solution:
//TC:O(n^2)
//SC:O(1)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int ans=0;
      
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    int c=0;
                    for(int k=0;k<4;k++){
                        int nr = i + m[k][0], nc = j + m[k][1];
                        if(nr>=0 && nr<grid.size()&& nc>=0 && nc<grid[i].size()){
                            if(grid[nr][nc]==1)
                            c++;
                        }
                    }
                ans+=(4-c);
                }
            }
        }
        return ans;
    }
};
