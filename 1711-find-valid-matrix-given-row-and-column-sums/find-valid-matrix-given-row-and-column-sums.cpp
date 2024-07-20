class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size(), 0));
        for(int i=0;i<rowSum.size();i++){
            for(int j=0;j<colSum.size();j++){
                int p = min(rowSum[i],colSum[j]);
                ans[i][j] = p;
                rowSum[i] = rowSum[i]-p;
                colSum[j] = colSum[j]-p;
            }
        }
        return ans;
    }
};