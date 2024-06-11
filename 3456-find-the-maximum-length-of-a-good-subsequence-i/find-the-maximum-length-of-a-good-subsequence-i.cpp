class Solution {
public:
    int f(vector<vector<vector<int>>> &dp, int i,int prev,int k,vector<int>& nums){
        if(i == nums.size())
        return dp[i][k][prev+1]= 0;

        if(dp[i][k][prev+1]!= -1){
            return dp[i][k][prev+1];
        }
        
        int take =0;
        if(prev == -1 || nums[prev] == nums[i]){
            take = 1 + f(dp,i+1,i,k,nums);
        }
        else if(k>0){ 
            take = 1 + f(dp,i+1,i,k-1,nums);
        }
        int ntake = f(dp,i+1,prev,k,nums);
        return dp[i][k][prev+1]= max(take,ntake);
    }

    int maximumLength(vector<int>& nums, int k) {
        vector<vector<vector<int>>> dp(nums.size() + 1, vector<vector<int>>(k + 1, vector<int>(nums.size() + 1, -1)));
        return f(dp,0,-1,k, nums);
    }
};