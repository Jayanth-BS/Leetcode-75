class Solution {
public:
int max1=0;
    int f(vector<int> &nums, int tgt, int i,int k,vector<vector<int>> &dp){
        if(tgt<0)
            return -100;
        if(tgt == 0){
            max1=max(max1,k);
            return 0;
        }
        if(i == nums.size())
            return -100;
        if(dp[tgt][i]!= -1)
            return dp[tgt][i];
           
        
        return dp[tgt][i] = max(f(nums,tgt,i+1,k,dp),1 + f(nums,tgt-nums[i],i+1,k+1,dp));
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int tgt) {
        vector<vector<int>> dp(tgt+1,vector<int>(nums.size(),-1));
        int x=f(nums,tgt,0,0,dp);
        
        if(max1==0)
        return -1;
        // for(int i=0;i<dp.size();i++){
        //     for(int j=0;j<dp[0].size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return x;
        
    }
};