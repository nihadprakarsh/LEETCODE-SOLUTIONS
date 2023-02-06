class Solution {
public:
    vector<int> pre(vector<int>&nums,vector<int>&dp,int len)
    {
        int n = nums.size();
        int ans=0,s=0,smax=0;
        int i=0,j=0;
        while(j<n)
        {
            s+=nums[j];
            if(j-i+1==len)
            {
                smax=max(smax,s);
                dp[j]=smax;
                s-=nums[i++];
            }
            j++;
        }
        return dp;
    }
    vector<int> suff(vector<int>&nums,vector<int>&dp,int len)
    {
        int n = nums.size();
        int ans=0,s=0,smax=0;
        int i=nums.size()-1,j=nums.size()-1;
        while(j>=0)
        {
            s+=nums[j];
            if(i-j+1==len)
            {
                smax=max(smax,s);
                dp[j]=smax;
                s-=nums[i--];
            }
            j--;
        }
        return dp;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int a, int b) {
        int n=nums.size(),ans=0;
        vector<int> dp1(n,0),dp2(n,0);
        dp1=pre(nums,dp1,a);
        dp2=suff(nums,dp2,b);
        for(int i=0;i<nums.size()-1;++i)
        ans=max(dp1[i]+dp2[i+1],ans);
        dp1.resize(n,0), dp2.resize(n,0);
        dp1=pre(nums,dp1,b);
        dp2=suff(nums,dp2,a);
        for(int i=0;i<nums.size()-1;++i)
        ans=max(dp1[i]+dp2[i+1],ans);
        return ans;
    }
};