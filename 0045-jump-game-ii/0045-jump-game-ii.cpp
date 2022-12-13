class Solution {
public:
    int dp[10005];
    int jump(vector<int>& nums) {
        memset(dp, 0, sizeof(dp));
        for(int ind = nums.size()-2; ind>=0; --ind)
        {
            long long int ans = INT_MAX;
            for(int i = 1; i <= nums[ind]; ++i)
            {
                if(i+ind <= nums.size()-1)
                ans = min(ans+0LL,1LL + dp[ind+i]);
            }
            dp[ind] = ans;
        }
        return dp[0];
    }
};