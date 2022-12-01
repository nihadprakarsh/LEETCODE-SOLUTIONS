class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        return i>=0 && i < grid.size() && j >=0 && j < grid[0].size();
    }
    int bfs(vector<vector<int>>&grid, int i, int j)
    {
        queue<pair<pair<int,int>, int>> q;
        q.push({{i,j}, 1});
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vis[i][j] = 1;
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            if(x == n-1 && y == m-1)
            return steps;
            
            int drow[] = {0,1,0,-1,1,1,-1,-1};
            int dcol[] = {1,0,-1,0,-1,1,-1,1};
            for(int ind =0; ind < 8; ++ind)
            {
                int nrow = x + drow[ind];
                int ncol = y + dcol[ind];
                if(isValid(nrow,ncol,grid) && !vis[nrow][ncol] && grid[nrow][ncol] == 0)
                {
                    q.push({{nrow,ncol}, steps+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        return bfs(grid, 0, 0);
    }
};