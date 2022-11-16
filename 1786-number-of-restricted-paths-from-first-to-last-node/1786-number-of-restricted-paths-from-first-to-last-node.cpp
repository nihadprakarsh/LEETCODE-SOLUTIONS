class Solution {
public:
    typedef pair<int,int> pt;
    int dp[100001];
    int mod = 1e9 + 7;
    int find(int n, vector<int>&dist, vector<pair<int,int>> adj[])
    {
        if(n==1) return 1;
        if(dp[n] != -1) return dp[n];
        int sum = 0;
        for(auto nodes : adj[n])
        {
            int wt = dist[n];
            int wt1 = dist[nodes.first];
            if(wt1 > wt) 
            sum = (sum + find(nodes.first,dist,adj))%mod;
        }
        return dp[n] = sum%mod;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int> dist(n+1,INT_MAX);
        dist[n] = 0;
        priority_queue<pt,vector<pt>,greater<pt>> q;
        q.push({0,n});
        while(!q.empty())
        {
            int node = q.top().second;
            int steps = q.top().first;
            q.pop();
            
            for(auto nodes : adj[node])
            {
                int adjNode = nodes.first;
                int wt = nodes.second;
                if(dist[adjNode] > wt + steps)
                {
                    dist[adjNode] = wt + steps;
                    q.push({dist[adjNode], adjNode});
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        return find(n,dist,adj)%mod;
    }
};