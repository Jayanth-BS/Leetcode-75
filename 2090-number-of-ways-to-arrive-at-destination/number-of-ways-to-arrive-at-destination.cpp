using ll = long long;             //vvimp
class Solution {
public:
    ll mod = (long long )1e9 +7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>> adj[n];
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        vector<ll> dis(n,LONG_MAX);           ///imp
        vector<ll> ways(n,0);
        ways[0] = 1;
        dis[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            ll dist = it.first;
            ll node = it.second;
            pq.pop();
            for(auto i: adj[node]){
                ll time = i.second;
                ll adjn = i.first;
                if(time+ dist<dis[adjn]){
                    dis[adjn] = dist + time;
                    ways[adjn] = ways[node];
                    pq.push({dis[adjn], adjn});
                }   
                else if(time + dist==dis[adjn]){
                    ways[adjn] = (ways[node]+ways[adjn]) % mod;
                }
            }
        }
        return ways[n-1]%mod; 
    }
};