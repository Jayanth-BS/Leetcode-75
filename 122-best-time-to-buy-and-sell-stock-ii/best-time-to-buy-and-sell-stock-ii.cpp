class Solution {
public:
    int t[30004][2];
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        int n = prices.size();
        t[n][0]=0;
        t[n][1]=0;
        for(int i = n-1;i>=0;i--){
                int profit=0;
                t[i][1] = max(-prices[i] + t[i+1][0], 0 + t[i+1][1]); 
                t[i][0] = max(prices[i] + t[i+1][1], 0 + t[i+1][0]);
        }
        return t[0][1];
    }
};