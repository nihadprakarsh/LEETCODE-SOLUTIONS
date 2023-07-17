class Solution {
public:
    int dp[100001][2];
    int find(vector<int>&prices,int buy,int ind)
    {
        if(ind == prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit = 0;
        if(buy == 0)
            profit = max(profit,max(-prices[ind]+find(prices,1,ind+1),find(prices,0,ind+1)));
        else
            profit = max(profit,max(prices[ind]+find(prices,0,ind+1),find(prices,1,ind+1)));
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return find(prices,0,0);
    }
};