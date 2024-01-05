class Solution {
public:
    int dp[31][60001];
    int find(int ind,vector<int>&stones,int sum)
    {
        if(ind == stones.size())
        {
            if(sum < 0) return 1e9;
            return sum;
        }
        if(dp[ind][sum+30000] != -1) return dp[ind][sum+30000];
        int a=1e9;
        a=min(find(ind+1,stones,sum+stones[ind]),find(ind+1,stones,sum-stones[ind]));
        return dp[ind][sum+30000]=a;
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return find(0,stones,0);
    }
};