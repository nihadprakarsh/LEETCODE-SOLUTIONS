class Solution {
public:
    int dp[5*10001+1][3];
    int find(int ind,int c,vector<int>&values)
    {
        if(ind==values.size())
        return -1e8;
        if(dp[ind][c]!=-1) return dp[ind][c];
        int a=0,b=0;
        if(c==2)
        a=find(ind+1,c-1,values)+values[ind]+ind;
        else
        a=values[ind]-ind;
        b=find(ind+1,c,values);
        return dp[ind][c]=max(a,b);
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        return find(0,2,values);
    }
};