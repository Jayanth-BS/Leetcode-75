class Solution {
public:
    long long f(int i,int p, vector<int>& nums,vector<vector<long long>> &dp){
        if(i >= nums.size()){
            return 0;
        }

        if(dp[i][p]!= INT_MIN)
            return dp[i][p];

        long long m = INT_MIN;
        long long n = INT_MIN;

        if(p == 0){
            m = -nums[i] + f(i+1,1,nums,dp);
        }
        n = nums[i] + f(i+1,0,nums,dp);

        return dp[i][p] = max(m,n);
    }

    long long maximumTotalCost(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size()+1,vector<long long>(2,INT_MIN));
        return nums[0] +f(1,0,nums,dp);
    }

};