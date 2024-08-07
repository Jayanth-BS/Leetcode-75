class Solution {
public:
    int dp[100004][2][3];
    int f(int i, int buy, int k, vector<int> & prices){
        if(dp[i][buy][k] != -1)
        return dp[i][buy][k];

        if(k == 2 || i == prices.size())
        return 0;
        
        long pf;
        
        if(buy){
            pf = max(-prices[i] + f(i+1,0,k, prices), 0 + f(i+1,1,k, prices));
        }
        else{
            pf = max(prices[i] + f(i+1,1,k+1, prices), 0 + f(i+1,0,k, prices));
        }
        return  dp[i][buy][k] = pf;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(0,1,0, prices);
    }
};