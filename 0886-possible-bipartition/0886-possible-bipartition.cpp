class Solution {
public:
    bool bfs(int i, vector<int> adj[], int color[])
    {
        queue<pair<int,int>> q;
        q.push({i,1});
        color[i] = 1;
        while(!q.empty())
        {
            int node = q.front().first;
            int initcolor = q.front().second;
            q.pop();
            
            for(auto nodes : adj[node])
            {
                if(color[nodes] == -1)
                {
                    color[nodes] = ~initcolor;
                    q.push({nodes,~initcolor});
                }
                
                else if(color[nodes] == initcolor)
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int color[n+1];
        memset(color, -1, sizeof(color));
        vector<int> adj[n+1];
        for(auto it : dislikes)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=1; i <=n ; ++i)
        {
            if(color[i] == -1)
            {
                if(!bfs(i,adj,color))
                    return false;
            }
        }
        return true;
    }
};