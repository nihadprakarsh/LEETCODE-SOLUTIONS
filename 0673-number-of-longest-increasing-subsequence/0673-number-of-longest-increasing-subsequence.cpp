class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n =  nums.size();
        int mx = 0;
        vector<int> dp(n,1), cnt(n,1);
        for(int i=0;i<n;++i)
        {
            for(int prev=0;prev<i;++prev)
            {
                if(nums[prev]<nums[i] && dp[prev]+1>dp[i])
                {
                    dp[i]=1+dp[prev];
                    cnt[i]=cnt[prev];
                }
                else if(nums[prev]<nums[i] && dp[prev]+1==dp[i]){
                    cnt[i]+=cnt[prev];
                }
            }
            mx=max(mx,dp[i]);
        }
        
        int res = 0;
        for(int i=0;i<dp.size();++i)
        {
            if(dp[i] == mx)
                res+=cnt[i];
        }
        return res;
    }
};