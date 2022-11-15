class Solution {
public:
    typedef pair<int,pair<int,int>> pt;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pt> q;
        vector<pair<int,int>> adj[n];
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
            // adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int> dist(n,1e9);
        //source,{stops,price};
        q.push({src,{0,0}});
        dist[src] = 0;
        while(!q.empty())
        {
            int sr = q.front().first;
            int stops = q.front().second.first;
            int price = q.front().second.second;
            q.pop();
            if(stops > k) continue;
            
            for(auto nodes : adj[sr])
            {
                int ds = nodes.first;
                int pr = nodes.second;
                if(stops <= k && dist[ds] > price + pr)
                {
                    dist[ds] = price + pr;
                    q.push({ds,{stops+1,dist[ds]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
    
};