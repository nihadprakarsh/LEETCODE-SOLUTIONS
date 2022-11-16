class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        set<int> st;
        for(auto it : restricted)
        st.insert(it);
        queue<int> q;
        q.push(0);
        vector<int> adj[n];
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n,0);
        int ans = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            for(auto nodes : adj[node])
            {
                if(!st.count(nodes) && !vis[nodes])
                {
                    ans++;
                    vis[nodes] = 1;
                    q.push(nodes);
                }
            }
        }
        return ans+1;
    }
};