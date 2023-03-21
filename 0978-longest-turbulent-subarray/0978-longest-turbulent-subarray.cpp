class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&v,int i , bool t ,int prev)
    {
        if(i==v.size())
          return 0;
        if(dp[prev][t]!=-1)
            return dp[prev][t];
        if(prev==0)
        {
    return dp[prev][t]=max({1+solve(v,i+1,0,i+1),1+solve(v,i+1,1,i+1),solve(v,i+1,t,prev)});
        }
        else if(t==0)
        {
            if(v[i]<v[prev-1])
                return dp[prev][t]=1+solve(v,i+1,1,i+1);
        }
        else
        {
            if(v[i]>v[prev-1])
                return dp[prev][t]=1+solve(v,i+1,0,i+1);
        }
         return dp[prev][t]=0;
    }
    int maxTurbulenceSize(vector<int>& arr)
    {
       int n=arr.size();
        dp.resize(n+1,vector<int>(3,-1));
       return solve(arr,0,0,0);                     
    }
};