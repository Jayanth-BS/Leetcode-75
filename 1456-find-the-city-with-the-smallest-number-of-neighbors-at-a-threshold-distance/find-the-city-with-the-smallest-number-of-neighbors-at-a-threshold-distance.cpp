class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> path(n+1,vector<int>(n+1,1e9));
        for(auto i: edges){
            int u = i[0];
            int v =i[1];
            int wt = i[2];
            path[u][v] = wt;
            path[v][u] = wt;
        }
        for(int k=0;k<n;k++){path[k][k] =0;}
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    path[i][j] = min(path[i][j] , path[i][k]+path[k][j]);
                }
            }
        }
        int prev=n,city=-1;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(path[i][j] <= distanceThreshold){
                    c++;
                }
            }
            if(c <= prev){
                city = i;
                prev = c;
            }
        }
        
        return city;
    }
};