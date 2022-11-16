class Solution {
public:
    typedef pair<long long int,long long int> pt;
    typedef long long int ll;
    ll mod = (int)1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // map<int,int> m;
        vector<pair<ll,ll>> adj[n];
        for(auto &it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<ll> dist(n,LONG_MAX), ways(n,0);
        priority_queue<pt,vector<pt>,greater<pt>> q;
        dist[0] = 0;
        ways[0] = 1;
        q.push({0,0});
        
        while(!q.empty())
        {
            ll node = q.top().second;
            ll steps = q.top().first;
            q.pop();
            
            for(auto nodes : adj[node])
            {
                ll adjNode = nodes.first;
                ll cost = nodes.second;
                if(dist[adjNode] > cost + steps)
                {
                    dist[adjNode] = cost + steps;
                    q.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dist[adjNode] == cost + steps)
                {
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
                else continue;
            }
        }
        // if(ways[n-1]%mod == 0) return 1;
        return ways[n-1]%mod;
        
    }
};