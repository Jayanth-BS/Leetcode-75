class Solution {
public:
    int f(int i,int j, string word1,string word2, vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=0)
        return dp[i][j];
        if(word1[i] == word2[j]){
            return f(i-1,j-1,word1,word2,dp);
        }
        return dp[i][j] = min(min(1+f(i,j-1,word1,word2,dp), 1+f(i-1,j,word1,word2,dp)),1+f(i-1,j-1,word1,word2,dp));
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        return f(m,n, word1,word2,dp);
    }
};