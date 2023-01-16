class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        vector<long long> dp(nums.size(),0);
        long long ans=0;
        map<long long,long long> m;
        for(int i=0;i<nums.size();++i)
        {
            dp[i]=max(0LL,i-m[i-nums[i]]);
            m[i-nums[i]]++;
        }
        long long s=0;
        for(int i=0;i<dp.size();++i)
        s+=dp[i];
        return s;
    }
};