class Solution {
public:
    bool bfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&vis)
    {
        vis[i][j] = 1;
        bool flag = true;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            auto di = q.front().first;
            auto dj = q.front().second;
            q.pop();
            if(di == 0 || di == grid.size()-1 || dj ==0 || dj == grid[0].size()-1)
            flag=  false;
            int drow[] = {0,1,0,-1};
            int dcol[] = {1,0,-1,0};
            for(int k=0 ;k <4; ++k)
            {
                int nrow = di + drow[k];
                int ncol = dj + dcol[k];
                if(nrow >=0 && nrow < grid.size() && ncol >=0 && ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] != 1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m = grid[0].size();
        int ans =0 ;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i < n; ++i)
        {
            for(int j =0; j < m; ++j)
            {
                if(!vis[i][j] && grid[i][j] == 0)
                {
                    bool k = bfs(i,j,grid,vis);
                    if(k)
                    ans++;
                }
            }
        }
        return ans;
    }
};