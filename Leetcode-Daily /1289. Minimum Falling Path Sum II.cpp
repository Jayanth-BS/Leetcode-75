// Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

// A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column
// Solution:

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[0][i] = grid[0][i];
        }
        for(int i=1;i<n;i++){
                int mn1 = INT_MAX, mn1_i=0;
                int mn2 = INT_MAX, mn2_i=0;
                for(int k=0;k<m;k++){
                    if(dp[i-1][k]<mn1){
                        mn1 = min(mn1,dp[i-1][k]);
                        mn1_i = k;
                    }
                }
                for(int k=0;k<m;k++){
                    if(dp[i-1][k]<mn2 &&  ((dp[i-1][k]>=mn1 && mn1_i!=k)||dp[i-1][k]>mn1)){
                        mn2 = min(mn2,dp[i-1][k]);
                        mn2_i = k;
                    }
                }
                cout<<mn1<<" "<<mn2<<endl;
            for(int j=0;j<m;j++){
                if(mn1_i==j){
                    dp[i][j] = grid[i][j]+mn2;
                }
                else{
                    dp[i][j] = grid[i][j]+mn1;
                }
            }
        }
        int mn_sum = INT_MAX;
        for(int i=0;i<m;i++){
            mn_sum = min(mn_sum,dp[n-1][i]);
        }
        return mn_sum;
    }
};


               
