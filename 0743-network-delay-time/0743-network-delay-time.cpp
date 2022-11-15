class Solution {
public:
    typedef pair<int,int> pt;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it :times)
        adj[it[0]].push_back({it[1], it[2]});
        int ans = 0;
        priority_queue<pt,vector<pt>,greater<pt>> q;
        q.push({0,k});
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        while(!q.empty())
        {
            auto node = q.top().second;
            auto time = q.top().first;
            q.pop();
            
            for(auto nodes : adj[node])
            {
                auto adjNode = nodes.first;
                auto newTime = nodes.second;
                if(dist[adjNode] > time + newTime)
                {
                    dist[adjNode] = time + newTime;
                    q.push({dist[adjNode], adjNode});
                }
            }
        }
        for(int i = 1 ; i <= n ; ++i)
        if(dist[i] == 1e9) return -1;
        for(int i = 1; i <= n; ++i)
        ans = max(ans, dist[i]);
        return ans;
    }
};