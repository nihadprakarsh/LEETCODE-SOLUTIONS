class Solution {
public:
    int dist = INT_MAX;
    typedef pair<pair<int,int>,int> pt;
    queue<pt> q;
    void dfs(int i, int j, vector<vector<int>>&grid)
    {
        grid[i][j] = 2;
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        for(int k =0 ; k< 4; ++k)
        {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if(nrow >=0 && nrow<grid.size() && ncol >=0 && ncol < grid[0].size() && 
               grid[nrow][ncol] != 2 && grid[nrow][ncol] != 0)
            {
                dfs(nrow,ncol,grid);
                q.push({{nrow,ncol},0});
            }
        }
    }
    
    void bfs(vector<vector<int>>&grid)
    {
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto i = q.front().first.first;
                auto j = q.front().first.second;
                int steps = q.front().second;

                q.pop();

                int drow[] = {0,1,0,-1};
                int dcol[] = {1,0,-1,0};
                for(int k =0; k < 4; ++k)
                {
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];
                    if(nrow>=0 && nrow< grid.size() && ncol >=0 && ncol < grid[0].size() && grid[nrow][ncol] == 1)
                    dist = min(steps,dist);
                    else if(nrow >=0 && nrow < grid.size() && ncol >=0 && ncol < grid[0].size() && 
                            grid[nrow][ncol]==0){
                    grid[nrow][ncol] = 2;
                    q.push({{nrow,ncol},steps+1});
                    }
                }
            }
        }
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        //marking the first island
        bool flag = false;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i < n; ++i)
        {
            for(int j=0; j < m; ++j)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i,j,grid);
                    q.push({{i,j},0});
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
        bfs(grid);
        return dist;
    }
};