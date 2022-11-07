class Solution {
public:
    int dp[1001][1001];
    int mod = 1e9 + 7;
    int dfs(vector<vector<int>>&grid, int i, int j,vector<vector<int>>&vis)
    {
        if(dp[i][j] != -1) return dp[i][j];
        int sum = 0;
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        for(int ind = 0; ind < 4; ++ind)
        {
            int nrow = i + drow[ind];
            int ncol = j + dcol[ind];
            if(nrow >=0 && nrow < grid.size() && ncol >=0 && ncol < grid[0].size() &&
              grid[nrow][ncol] > grid[i][j]){
                sum = (sum + 1 + dfs(grid,nrow,ncol,vis))%mod;
            }
        }
        return dp[i][j] = sum;
    }
    int countPaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i < n; ++i)
        {
            for(int j =0; j < m; ++j)
                ans = (ans + dfs(grid,i,j,vis))%mod;
        }
        return (ans+(n*m))%mod;
    }
};