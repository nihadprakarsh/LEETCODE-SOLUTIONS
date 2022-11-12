class Solution {
public:
    vector<int> temp;
    void dfs(int i, vector<int> adj[],vector<int>&vis){
        for(auto nodes : adj[i]){
            if(!vis[nodes]){
                temp.push_back(nodes);
                vis[nodes] = 1;
                dfs(nodes,adj,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it : edges)
        adj[it[1]].push_back(it[0]);
        vector<vector<int>> ans;
        for(int i=0; i < n ; ++i){
            vector<int> vis(n,0);
            temp.clear();
            dfs(i,adj,vis);
            sort(begin(temp), end(temp));
            ans.push_back(temp);
        }
        return ans;
    }
};