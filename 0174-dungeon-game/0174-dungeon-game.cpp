class Solution {
public:
    int dp[201][201];
    int find(vector<vector<int>>& dungeon, int i, int j)
    {
        if(i < 0 || j < 0 || i ==dungeon.size() || j == dungeon[0].size())
            return (int)1e9;
        if(i==dungeon.size()-1 && j == dungeon[0].size()-1)
        {
            if(dungeon[i][j] < 0)
                return 1 - dungeon[i][j];
            else
                return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int a = 0, b =0 ;
        a = find(dungeon, i+1, j);
        b = find(dungeon, i, j+1);
        int t = min(a,b) - dungeon[i][j];
        return dp[i][j] = t<=0?1:t;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp, -1, sizeof(dp));
        return find(dungeon, 0, 0);
    }
};