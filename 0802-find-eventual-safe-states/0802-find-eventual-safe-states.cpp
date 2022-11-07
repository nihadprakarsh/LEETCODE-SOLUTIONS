class Solution {
public:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], int check[]){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto nodes : adj[node]){
            if(!vis[nodes]){
                if(dfs(nodes,adj,vis,pathVis,check))
                    return true;
            }
            else if(pathVis[nodes])
                return true;
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        for(int i=0 ; i < graph.size(); ++i){
            for(auto nodes : graph[i]){
                adj[i].push_back(nodes);
            }
        }
        int vis[V], pathVis[V], check[V];
        memset(vis, 0, sizeof(vis));
        memset(pathVis, 0, sizeof(pathVis));
        memset(check, 0, sizeof(check));
        for(int i =0; i < V; ++i){
            if(!vis[i]){
                dfs(i, adj, vis, pathVis, check);
            }
        }
        vector<int> ans;
        for(int i=0; i < V; ++i){
            if(check[i])
                ans.push_back(i);
        }
        return ans;
    }
};