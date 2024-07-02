class Solution {
public: // tabulation
    int change(int amt, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amt+1,0));
        for(int t =0;t<=amt;t++)
        dp[0][t] = (t%coins[0]==0);

        for(int i=1;i<coins.size();i++){
            for(int j = 0;j<=amt;j++){
                    int ntake = dp[i-1][j];
                    int  take =0;
                    if(j>=coins[i])
                        take= dp[i][j-coins[i]];
                   dp[i][j] = take + ntake;
            }
        }
        return dp[coins.size()-1][amt];
    }
};


//Recursion & do memoization for this
    // int f(int i,int amt, vector<int>& coins){
    //     if(i ==0){
    //         return (amt%coins[0]==0);
    //     }
    //     int ntake = f(i-1, amt, coins);
    //     int  take =0;
    //     if(amt>=coins[i])
    //     take= f(i,amt-coins[i], coins);
    //     return take + ntake;
    // }
    // int change(int amt, vector<int>& coins) {
    //     return f(coins.size()-1,amt,coins);
    // }