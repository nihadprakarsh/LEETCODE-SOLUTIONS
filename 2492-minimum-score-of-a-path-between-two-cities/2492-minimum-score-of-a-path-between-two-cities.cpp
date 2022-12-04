class Solution {
public:
    typedef pair<int,int> pt;
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pt> adj[n+1];
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pt, vector<pt>, greater<pt>> q;
        vector<int> dist(n+1,INT_MAX);
        q.push({1e9,1});
        while(!q.empty())
        {
            int node = q.top().second;
            int steps = q.top().first;
            q.pop();
            for(auto nodes : adj[node])
            {
                int adjNode = nodes.first;
                int wt = nodes.second;
                if(dist[adjNode] > min(wt,steps))
                {
                    dist[adjNode] = min(wt,steps);
                    q.push({dist[adjNode],adjNode});
                }
            }
        }
        
        return dist[n];
    }
};