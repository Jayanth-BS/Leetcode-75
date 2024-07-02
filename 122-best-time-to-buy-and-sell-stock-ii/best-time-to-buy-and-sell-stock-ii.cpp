class Solution {
public:
    int t[30004][2];
    int f(int i, int buy,vector<int>& prices){
        if(t[i][buy]!= -1)
        return t[i][buy];

        if(i == prices.size()) 
        return 0;
       
        int profit=0;//as profit = sp-cp..so sub in buying and add in selling
        if(buy){  //case where u have option to buy
            profit = max(-prices[i] + f(i+1,0,prices), 0 + f(i+1,1,prices)); // buy or keep
        }
        else{//case where u have option to sell
            profit = max(prices[i] + f(i+1,1,prices), 0 + f(i+1,0,prices)); //sell or keep
        }
        return t[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return f(0,1,prices);
    }
};