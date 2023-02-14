class Solution {
public:
    int dp[1001][1002];
    int find(int ind,int prev,vector<vector<int>>& pairs)
    {
        if(ind==pairs.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int a=0;
        if(prev==-1 || pairs[ind][0]>pairs[prev][1])
        a=1+find(ind+1,ind,pairs);
        a=max(a,find(ind+1,prev,pairs));
        return dp[ind][prev+1]=a;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs),end(pairs));
        memset(dp,-1,sizeof(dp));
        return find(0,-1,pairs);
    }
};