class Solution {
public:
    typedef pair<int,int> pt;
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pt,vector<pt>,greater<pt>> q;
        int n = points.size();
        vector<pt> adj[n];
        for(int i=0; i < points.size(); ++i)
        {
            for(int j =0; j < points.size(); ++j)
            {
                if(i != j)
                {
                    int val = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    adj[i].push_back({val,j});
                }
            }
        }
        
        // priority_queue<pt,vector<pt>,greater<pt>> q;
        int sum  =0;
        vector<int> vis(n,0);
        q.push({0,0});
        while(!q.empty())
        {
            int node = q.top().second;
            int wt = q.top().first;
            q.pop();
            
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            for(auto nodes : adj[node]){
               int adjNode = nodes.second;
               int wtt = nodes.first;
               if(!vis[adjNode]){
                   q.push({wtt,adjNode});
               }
           }
        }
        return sum;
    }
};