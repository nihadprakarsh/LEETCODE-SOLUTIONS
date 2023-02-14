class Solution {
public:
    int dp[59][3];
    int find(int n,int c)
    {
        if(n==0) return 1;
        if(dp[n][c]!=-1) return dp[n][c];
        int a=0;
        for(int i=1;i<=n;++i)
        {
            if(c>1 && n-i>0)
            a=max(a,find(n-i,c-1)*i);
            else if(c==1 && n-i>=0)
            a=max(a,find(n-i,c)*i);
        }
        return dp[n][c]=a;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return find(n,2);
    }
};