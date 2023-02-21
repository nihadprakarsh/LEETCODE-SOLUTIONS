class Solution {
public:
    int dp[5*100000+1][4];
    int find(int ind,int lane,vector<int>&o)
    {
        if(ind==o.size()-1) return 0;
        if(dp[ind][lane]!=-1) return dp[ind][lane];
        int a=1e8;
        if(o[ind+1]!=lane)
        a=min(a,find(ind+1,lane,o));
        else if(o[ind+1]==lane)
        {
            for(int i=1;i<=3;++i)
            if(i!=lane && o[ind]!=i)
            a=min(a,1+find(ind,i,o));
        }
        return dp[ind][lane]=a;
    }
    int minSideJumps(vector<int>& o) {
        memset(dp,-1,sizeof(dp));
        return find(0,2,o);
    }
};