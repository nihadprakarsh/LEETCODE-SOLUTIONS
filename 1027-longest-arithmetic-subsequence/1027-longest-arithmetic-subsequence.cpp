class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2000,0));
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int d=nums[j]-nums[i]+1000;
                dp[j][d]=dp[i][d]>0?1+dp[i][d]:2;
                ans=max(ans,dp[j][d]);
            }
        }
        return ans;
    }
};