class Solution {
public:
    int mod=1e9+7;
    int rev(int n)
    {
        int r=0;
        while(n != 0) {
        int remainder = n % 10;
        r = r * 10 + remainder;
        n /= 10;
      }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        vector<long long int> dp(nums.size(),0);
        map<int,int> m;
        for(int i=0;i<nums.size();++i)
        {
            int ans=0;
            int k = nums[i]-rev(nums[i]);
            dp[i]=m[k];
            m[k]++;
        }
        long long int s=0;
        for(int i=0;i<dp.size();++i)
        s+=dp[i];
        return s%mod;
    }
};