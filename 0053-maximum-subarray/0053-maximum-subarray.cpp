class Solution {
public:
    int n;
    int fn(int i,vector<int>&v,vector<int>&dp){
        if(i==n-1){
            if(v[i]>0) return v[i];
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int maxi=0;
        maxi=max(0,v[i]+fn(i+1,v,dp));
        return dp[i]=maxi;
    }
    int maxSubArray(vector<int>& nums) {
        n=nums.size();
        vector<int>dp(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                ans=max(ans,fn(i,nums,dp));
        }
        if(ans==0)
            return *max_element(nums.begin(),nums.end());
        return ans;
    }
};