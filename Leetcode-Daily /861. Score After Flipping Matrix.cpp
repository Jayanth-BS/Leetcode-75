// You are given an m x n binary matrix grid.  
// A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's). 
// Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.  
// Return the highest possible score after making any number of moves (including zero moves).


class Solution {
public:
int matrixScore(vector<vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();
  for(int i=0;i<m;i++){
    if(grid[i][0] == 0){
      for(int j=0;j<n;j++){
        grid[i][j] = !grid[i][j];
      }
    }
  }
  for(int i=0;i<n;i++){
    int c=0;
    for(int j=0;j<m;j++){
      if(grid[j][i] == 0)c++;
    }
    if(c>(m/2)){
      for(int j=0;j<m;j++){
        grid[j][i] = !grid[j][i];
      }
    }
  }
  int sum =0;
  for(int i=0;i<m;i++){
    int ans =0;
    for(int j=0;j<n;j++){
      cout<<grid[i][j]<<' ';
      if(grid[i][j])
        ans = ans | 1 << (n-j-1);
    }
    cout<<'\n';
    sum +=ans;
  }
  return sum;
}
};
