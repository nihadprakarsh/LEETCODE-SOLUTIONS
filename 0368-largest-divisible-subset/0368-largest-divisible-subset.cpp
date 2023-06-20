class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // if(nums.size() == 1) return nums;
        int n = nums.size();
        int mx = 1, lastIndex = 0;
        vector<int> dp(n,1), hash(n);
        sort(begin(nums),end(nums));
        for(int i=0;i<n;++i)
        {
            hash[i] = i;
            for(int prev=0;prev<i;++prev)
            {
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i] > mx){
                mx=dp[i];
                lastIndex=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};