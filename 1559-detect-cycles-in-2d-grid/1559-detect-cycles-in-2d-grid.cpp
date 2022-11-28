class Solution {
public:
    bool isValid(int i, int j, vector<vector<char>>&grid)
    {
        return i>=0 && i < grid.size() && j >=0 && j < grid[0].size();
    }
    bool dfs(int i, int j, int prevR, int prevC, vector<vector<char>>& grid, vector<vector<int>> &vis, char cc)
    {
        bool flag = false;
        vis[i][j] = 1;
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        for(int ind = 0 ; ind < 4; ++ind)
        {
            int nrow = i + drow[ind];
            int ncol = j + dcol[ind];
            if(isValid(nrow,ncol,grid))
            {
                if(!(nrow == prevR && ncol == prevC))
                {
                    if(grid[nrow][ncol] == cc)
                    {
                        if(vis[nrow][ncol])
                        return true;
                        else
                        flag = flag | dfs(nrow,ncol,i,j,grid,vis,cc);
                    }
                    
                }
            }
        }
        return flag;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int flag = false;
        for(int i=0; i < n; ++i)
        {
            for(int j=0 ; j < m; ++j)
            {
                if(!vis[i][j])
                flag |= dfs(i,j,-1,-1,grid,vis,grid[i][j]);
            }
        }
        return flag;
    }
};