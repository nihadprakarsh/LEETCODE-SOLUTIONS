class Solution {
public:
    int dp[10005];
    int find(vector<int>& nums, int ind)
    {
        if(ind == nums.size()-1) return 0;
        if(dp[ind] != -1) return dp[ind];
        long long int ans = INT_MAX;
        for(int i = 1; i <= nums[ind]; ++i)
        {
            if(i+ind <= nums.size()-1)
            ans = min(ans+0LL,1LL + find(nums,ind+i));
        }
        return dp[ind] = ans;
    }
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return find(nums,0);
    }
};