class Solution {
public:
    int ahead[2], cur[2];
    int maxProfit(vector<int>& prices) {
        memset(ahead,0,sizeof(ahead));
        memset(cur,0,sizeof(cur));
        int n = prices.size();
        ahead[0] = 0;
        ahead[1] = 0;
        for(int i = n-1;i>=0;i--){
            cur[1] = max(-prices[i] + ahead[0], 0 + ahead[1]);
            cur[0] = max(prices[i] +ahead[1], 0 + ahead[0]);
            ahead[0] = cur[0] ;
            ahead[1] = cur[1];
        }    
        return ahead[1];
    }
};