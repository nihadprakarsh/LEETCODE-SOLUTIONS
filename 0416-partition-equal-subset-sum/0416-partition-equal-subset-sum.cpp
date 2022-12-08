class Solution {
public:
    int dp[200][10001];
    bool find(vector<int>& nums, int ind, int sum)
    {
        if(sum < 0) return false;
        if(ind >= nums.size())
        return sum == 0;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        return dp[ind][sum] = find(nums,ind+1,sum-nums[ind]) or find(nums,ind+1,sum);
    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(begin(nums), end(nums), 0);
        if(sum % 2) return false;
        return find(nums,0,sum/2);
    }
};