class Solution {
public:
    int dp[1001][1001];
    int find(string &s, string &t, int a, int b)
    {
        if(b == t.size()) return 1;
        if(a == s.size()) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        int a1 = 0;
        if(s[a] == t[b]) a1 +=find(s,t,a+1,b+1);
        return dp[a][b] = a1 += find(s,t,a+1,b);
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return find(s,t,0,0);
    }
};