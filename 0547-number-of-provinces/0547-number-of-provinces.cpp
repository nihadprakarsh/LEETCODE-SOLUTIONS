class Solution {
public:
    void dfs(vector<int> adj[], int i, vector<int>&vis)
    {
        for(auto path : adj[i])
        {
            if(!vis[path])
            {
                vis[path]=1;
                dfs(adj,path,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];
        for(int i=0; i < n; ++i)
        {
            for(int j =0; j < n; ++j)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int count =0;
        vector<int> vis(n+1,0);
        for(int i=1; i <=n; ++i)
        {
            if(!vis[i])
            {
                vis[i]=1;
                count++;
                dfs(adj,i,vis);
            }
        }
        return count;
    }
};