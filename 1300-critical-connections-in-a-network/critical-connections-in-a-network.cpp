class Solution {
public:
    int timer =0;
    void dfs(int node,int parent,vector<vector<int>> &bridges,vector<int> &time,vector<int>& low, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        low[node] = time[node] = timer;
        timer++;
        for(auto i: adj[node]){
            if(i == parent) continue;
            if(vis[i] == 0){
                dfs(i,node,bridges,time,low,adj,vis);
                low[node] = min(low[node],low[i]);
                if(low[i] > time[node]){
                    bridges.push_back({i,node});
                }    
            }
            else{
                low[node] = min(low[node],low[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n);
        vector<int> time(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        dfs(0,-1,bridges,time,low,adj,vis);
        return bridges;
    }
};