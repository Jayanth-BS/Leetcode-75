class Solution {
public:
    int find(int i,int total,int tgt,int sum, vector<int> &stones,vector<vector<int>> &dp){
        if(i == stones.size() || total>= tgt){
            return abs(total-(sum - total));
        }
        if(dp[i][total] != -1)
            return dp[i][total];
        return dp[i][total] = min(find(i+1,total+stones[i],tgt,sum,stones,dp),find(i+1,total,tgt,sum,stones,dp));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(auto i: stones)
        sum+=i;
        vector<vector<int>> dp(stones.size(),vector<int>(sum, -1));
        int tgt = ceil(sum/2);
        return find(0,0,tgt,sum,stones, dp);
    }
};