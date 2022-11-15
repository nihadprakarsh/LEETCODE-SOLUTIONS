class Solution {
public:
    static bool comp(pair<int,int>&a, pair<int,int> &b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
    
    int bfs(int i, int dt, vector<pair<int,int>> adj[], int n)
    {
        queue<pair<int,int>> q;
        q.push({i,0});
        vector<int> dist(n,1e9);
        dist[i] = 0;
        while(!q.empty())
        {
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            for(auto nodes : adj[node])
            {
                int adjNode = nodes.first;
                int newdis = nodes.second;
                if(dist[adjNode] > newdis + dis)
                {
                    dist[adjNode] = newdis + dis;
                    q.push({adjNode,newdis+dis});
                }
            }
        }
        
        int ans = 0;
        for(int i =0; i < n; ++i)
        if(dist[i] <= dt) ans++;
        return ans;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> v;
        vector<pair<int,int>> adj[n];
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        for(int i =0; i < n; ++i)
            v.push_back({bfs(i,distanceThreshold,adj,n),i});
        
        sort(begin(v), end(v), comp);
        return v[0].second;
    }
};