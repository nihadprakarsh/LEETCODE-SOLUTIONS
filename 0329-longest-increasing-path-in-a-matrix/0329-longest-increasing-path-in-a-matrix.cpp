class Solution {
public:
    int dp[200][200];
    int dfs(int i, int j, vector<vector<int>>&matrix)
    {
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        for(int ind = 0; ind < 4; ++ind){
            int nrow = i + drow[ind];
            int ncol = j + dcol[ind];
            if(nrow >=0 && nrow < matrix.size() && ncol >=0 && ncol < matrix[0].size() && 
              matrix[nrow][ncol] > matrix[i][j])
                a = max(a, 1 + dfs(nrow,ncol,matrix));
        }
        return dp[i][j]= a;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();
        for(int i= 0; i < n; ++i)
        {
            for(int j =0; j < m; ++j)
            {
                int k = dfs(i,j,matrix);
                ans = max(k,ans);
            }
        }
        return ans+1;
    }
};