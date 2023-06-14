class Solution {
public:
    // long long int ans = 0;
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = -1e9;
        int pre=1,suff=1;
        for(auto i=0;i<nums.size();++i)
        {
            if(pre == 0) pre=1;
            if(suff == 0) suff = 1;
            pre*=nums[i];
            suff*=nums[n-i-1];
            ans=max(ans,max(pre,suff));
        }
        return ans;
    }
};