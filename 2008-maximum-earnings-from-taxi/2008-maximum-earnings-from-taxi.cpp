class Solution {
public:
    long long dp[100005];
    long long bs(vector<vector<int>>&rides,int ind)
    {
        long long low=ind+1,high=rides.size()-1,mid,ans=rides.size();
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(rides[mid][0]>=rides[ind][1])
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
    long long dfs(vector<vector<int>>&rides, int ind)
    {
        if(ind>=rides.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        long long a=0,b=0;
        long long k = rides[ind][1];
        long long i=bs(rides,ind);
        a=rides[ind][1]-rides[ind][0]+rides[ind][2] + dfs(rides,i);
        b=dfs(rides,ind+1);
        return dp[ind]=max(a,b);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(begin(rides),end(rides));
        memset(dp,-1,sizeof(dp));
        return dfs(rides,0);
    }
};