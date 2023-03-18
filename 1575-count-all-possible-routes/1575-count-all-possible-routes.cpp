class Solution {
public:
    int dp[101][201];
    int mod=1e9+7;
    int find(vector<int>& locations, int start, int finish, int fuel)
    {
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        int a=start==finish;
        for(int i=0;i<locations.size();++i)
        {
            if(i!=start && abs(locations[i]-locations[start])<=fuel)
            a=(a+find(locations,i,finish,fuel-abs(locations[i]-locations[start])))%mod;
        }
        return dp[start][fuel]=a;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return find(locations,start,finish,fuel);
    }
};