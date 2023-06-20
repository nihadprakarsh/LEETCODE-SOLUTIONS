class Solution {
public:
    // double dp[101][101];
    double find(vector<int>& nums, int k, int ind, vector<vector<double>>&dp)
    {
        if(ind == nums.size()) return 0;
        if(dp[(int)ind][(int)k]!=-1) return dp[(int)ind][(int)k];
        if(k == 0)
        {
            double sum = 0;
            for(int i=ind;i<nums.size();++i)
                sum+=nums[i];
            double index = nums.size()-ind;
            return sum/(double)index;
        }
        
        double ans = 0, s = 0;
        for(int i=ind;i<nums.size();++i)
        {
            s+=nums[i];
            ans=max(ans,s/(double)(i-ind+1)+find(nums,k-1,i+1,dp));
        }
        return dp[(int)ind][(int)k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<vector<double>> dp(101,vector<double>(101,-1));
        return find(nums,k-1,0,dp);
    }
};