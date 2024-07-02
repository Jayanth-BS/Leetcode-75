class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0], profit=0,cost;
        for(int i=0;i<prices.size();i++){
            cost = prices[i]-mini;
            profit = max(profit,cost);
            mini = min(mini,prices[i]);
        }
        return profit;
    }
};