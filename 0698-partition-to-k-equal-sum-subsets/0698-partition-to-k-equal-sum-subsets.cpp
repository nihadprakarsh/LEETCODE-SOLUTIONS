class Solution {
public:
    int dp[100001][17];
    bool find(vector<int>&nums,int target,int curSum,int vis,int k)
    {
        if(k==1) return true;
        if(dp[vis][k]!=-1) return dp[vis][k];
        bool flg = false;
        if(curSum == target)
            return find(nums,target,0,vis,k-1);
        for(int i=0;i<nums.size();++i)
        {
            if((((1<<i)&vis)==0) && curSum + nums[i] <= target)
            {
                int temp = vis;
                vis|=(1<<i);
                flg = flg or find(nums,target,curSum+nums[i],vis,k);
                vis=temp;
            }
        }
        return dp[vis][k]=flg;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        int s = accumulate(begin(nums),end(nums),0);
        if(nums.size()<k||s%k) return false;
        return find(nums,s/k,0,0,k);
    }
};