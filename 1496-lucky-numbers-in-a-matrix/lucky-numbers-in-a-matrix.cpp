class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> col(m,INT_MIN);
        vector<int> row(n, INT_MAX);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]>matrix[i][j])
                    row[i] = matrix[i][j];
                if(col[j]<=matrix[i][j])
                    col[j] = matrix[i][j];
            }
        }
        // for(auto i: row)
        // cout<<i<<' '; 
        // cout<<'\n';
        //  for(auto i: col)
        // cout<<i<<' '; 
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++)
            {
                if(matrix[i][j] == col[j] && matrix[i][j] == row[i]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};