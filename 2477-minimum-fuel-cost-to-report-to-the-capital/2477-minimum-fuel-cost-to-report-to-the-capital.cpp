class Solution {
public:
    long long int ans =0 ;
    int bfs(int node, vector<int> adj[], vector<int> &vis, int seats)
    {
        int count = 1;
        vis[node] = 1;
        for(auto nodes : adj[node])
        {
            if(!vis[nodes])
            count += bfs(nodes,adj,vis,seats);
        }
        
        int x = count/seats;
        if(count % seats) x++;
        if(node != 0)
        ans += x;
        return count;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<int> adj[n+1];
        vector<int> vis(n+1,0);
        for(auto it : roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        bfs(0,adj,vis,seats);
        return ans;      
    }
};