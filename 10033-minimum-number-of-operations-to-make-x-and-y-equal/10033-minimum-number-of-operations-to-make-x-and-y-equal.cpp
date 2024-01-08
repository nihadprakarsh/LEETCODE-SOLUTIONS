class Solution {
public:
    int dp[10000+1];
    int find(int x,int y)
    {
        if(x<=y) return y-x;
        int ans=x-y;
        ans=min(ans,1+x%5+find(x/5,y));
        ans=min(ans,1+(5-x%5)+find(x/5+1,y));
        ans=min(ans,1+x%11+find(x/11,y));
        ans=min(ans,1+(11-x%11)+find(x/11+1,y));
        return dp[x]=ans;

    }
    int minimumOperationsToMakeEqual(int x, int y) {
        memset(dp,-1,sizeof(dp));
        return find(x,y);
    }
};