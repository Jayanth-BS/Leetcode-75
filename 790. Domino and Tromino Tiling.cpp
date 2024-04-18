// You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
// Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

class Solution {
public:
    int numTilings(int n) {
           long dp[n+3];
           dp[1] = 1;
           dp[2] = 2;
           dp[3] = 5;
           for(int i = 4;i<=n;i++){
                dp[i] = (dp[i-1]*2 + dp[i-3])%1000000007;
           }
           return dp[n];
    }
};
