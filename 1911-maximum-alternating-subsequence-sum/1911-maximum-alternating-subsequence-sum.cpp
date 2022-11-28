class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector< vector<long long>> dp(nums.size()+1, vector<long long> (2, 0));
        for(int ind = nums.size()-1; ind>=0; --ind)
        {
            for(int flag = 1; flag >=0; --flag)
            {
                long long a = 0, b= 0, c =0, d= 0;
                if(flag)
                a = dp[ind+1][0] + nums[ind];
                b = dp[ind+1][flag];
                if(!flag)
                c = dp[ind+1][1] - nums[ind];
                d = dp[ind+1][flag];
                long long maxi = max(a,(max(b,max(d,c))));
                dp[ind][flag] = maxi;
            }
        }
        return dp[0][1];
    }
};