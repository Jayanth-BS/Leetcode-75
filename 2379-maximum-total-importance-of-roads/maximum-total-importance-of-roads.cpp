class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       
        vector<int> degree(n,0);
        for(int i=0;i<roads.size();i++){
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }
        sort(degree.begin(),degree.end());
        long long k=0;
        for(int i=n;i>=1;i--){
            k += static_cast<long long>(degree[i-1])*i; 
        }
        return k;
    }
};