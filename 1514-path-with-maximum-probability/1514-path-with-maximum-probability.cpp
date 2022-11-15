class Solution {
public:
    typedef pair<int,double> pt;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        priority_queue<pt,vector<pt>,greater<pt>> q;
        q.push({start,-1});
        vector<double> dist(n,INT_MIN);
        dist[start] = INT_MAX;
        while(!q.empty())
        {
            int node = q.top().first;
            double succ = q.top().second;
            q.pop();
            
            for(auto nodes : adj[node])
            {
                int adjNode = nodes.first;
                double sucP = nodes.second;
                if(succ == -1 || succ * sucP > dist[adjNode])
                {
                    if(succ == -1)
                    dist[adjNode] = sucP;
                    else
                    dist[adjNode] = succ*sucP;
                    q.push({adjNode,dist[adjNode]});
                }
            }
        }
        if(dist[end] == INT_MIN) return 0;
        return dist[end];
    }
};