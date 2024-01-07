class Solution {
public:
    int dp[100001];
    bool find(vector<int>&nums,int ind)
    {
        if(ind == nums.size()) return true;
        bool flg=false;
        if(dp[ind]!=-1) return dp[ind];
        if(ind+2<nums.size() && ((nums[ind+1]-nums[ind]==1 and nums[ind+2]-nums[ind+1]==1) or (nums[ind+1]==nums[ind] and nums[ind+2]==nums[ind+1])))
            flg=flg or find(nums,ind+3);
        if(ind+1<nums.size() && nums[ind+1] == nums[ind])
            flg=flg or find(nums,ind+2);
        return dp[ind]=flg;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return find(nums,0);
    }
};