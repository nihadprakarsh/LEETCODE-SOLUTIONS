class Solution {
public:
    int dp[100001][3][4];
    int mod=1e9+7;
    int find(int n, int ab,int l)
    {
        if(n==0)
        return 1;
        if(dp[n][ab][l]!=-1) return dp[n][ab][l];
        long long a=0;
        for(int i=0;i<3;++i)
        {
            if(i==0 && ab+1<2)
            a=(a+find(n-1,ab+1,0))%mod;
            if(i==1 && l+1<3)
            a=(a+find(n-1,ab,l+1))%mod;
            if(i==2)
            a=(a+find(n-1,ab,0))%mod;
        }
        return dp[n][ab][l]=a;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return find(n,0,0);
    }
};