class Solution {
public:
    //Tabulation
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int> (cuts.size()+1,0));
        int c= cuts.size()-2;
        for(int i=c;i>=1;i--){
            for(int j=i;j<=c;j++){
                if(i>j) continue;
                int mini = 1e9;
                for(int k =i;k<=j;k++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini,cost);
                }
            dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};