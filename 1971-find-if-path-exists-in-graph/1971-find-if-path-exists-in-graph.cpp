class Solution {
public:
    bool dfs(int curr, vector<int> adj[], int des, vector<int> &vis)
    {
        if(curr == des)
            return true;
        bool flag=false;
        for(auto connected:adj[curr])
        {
            if(!vis[connected])
            {
                vis[connected]=1;
                flag = flag || dfs(connected,adj,des,vis);
            }
        }
        return flag;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<int> adj[n+1];
        vector<int> vis(n+1,0);
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vis[source] = 1;
        for(auto connected : adj[source])
        {
            if(!vis[connected])
            {
                vis[connected] = 1;
                if(dfs(connected,adj,destination,vis))
                    return true;
            }
        }
        return false;
    }
};