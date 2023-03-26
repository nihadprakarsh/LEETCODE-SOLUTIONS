class Solution {
public:
    int dp[10001];
    int find(int n)
    {
        if(n==0)
            return 0;
        if(dp[n] != -1) return dp[n];
        int mini = INT_MAX;
        for(int i =1 ; i <= sqrt(n); ++i)
            if(n-i*i>=0)
            mini = min(mini, 1 + find(n-(i*i)));
        return dp[n] = mini;
    }
    int numSquares(int n) {
        memset(dp, -1 ,sizeof(dp));
        return find(n);
    }
};