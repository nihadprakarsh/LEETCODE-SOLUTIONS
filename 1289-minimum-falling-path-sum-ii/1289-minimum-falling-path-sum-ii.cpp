class Solution {
public:
    int dp[200][200];
    int find(vector<vector<int>>& grid, int i, int j)
    {
        // if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
        // return (int)1e9;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == grid.size()-1)
        return grid[i][j];
        int ans = INT_MAX;
        for(int ind = 0; ind < grid[0].size(); ++ind)
            if(ind != j)
                ans = min(ans, (find(grid,i+1,ind) + grid[i][j]));
        
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int ans = INT_MAX;
        int m = grid[0].size();
        for(int i =0 ; i < m; ++i)
        ans = min(ans, find(grid,0,i));
        return ans;
    }
};