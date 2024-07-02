class Solution {
public:
    int f(int i,int amt, vector<int>& coins,vector<vector<int>> &dp){
        if(i ==0){
            return (amt%coins[0]==0);
        }
        if(dp[i][amt]!= -1)
        return dp[i][amt];
        int ntake = f(i-1, amt, coins,dp);
        int  take =0;
        if(amt>=coins[i])
        take= f(i,amt-coins[i], coins,dp);
        return dp[i][amt] = take + ntake;
    }
    int change(int amt, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amt+1,-1));
        return f(coins.size()-1,amt,coins,dp);
    }
};


//Recursion
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