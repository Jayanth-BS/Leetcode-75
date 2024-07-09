class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for( auto i: flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        q.push({0,{src,0}}); ///stops, node,dist 
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            int stop = it.first;
            int node = it.second.first;
            int d = it.second.second;
            q.pop();
            if(stop>k) continue;
            for(auto j:adj[node]){
                int gol = j.first;
                int wt = j.second;
                if(d + wt < dist[gol]  && stop<=k){
                    dist[gol] = wt + d;
                    q.push({stop+1,{gol,d+wt}});
                }       
            }
        }
        return (dist[dst] != 1e9)? dist[dst] : -1;
    }
};