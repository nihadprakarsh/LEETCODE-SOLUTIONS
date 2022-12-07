class Solution {
public:
    int dp[100][100];
    int find(vector<vector<int>>& matrix, int i, int j)
    {
        if(i < 0 || j < 0 || i == matrix.size() || j == matrix[0].size())
        return (int)1e9;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == matrix.size()-1)
        return matrix[i][j];
        int sum  = INT_MAX;
        for(int di = -1; di <= 1; ++di)
        sum = min(sum, (find(matrix,i+1,j+di) + matrix[i][j]));
        return dp[i][j] = sum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int m = matrix[0].size();
        int ans = INT_MAX;
        for(int i =0;  i < m; ++i)
        ans = min(ans, find(matrix,0,i));
        return ans;
    }
};