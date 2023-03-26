class Solution {
public:
    int dp[4][100000];
    int find(vector<int>&nums,int c,int an)
    {
        if(c==0)
        return an==0;
        if(dp[c][an]!=-1) return dp[c][an];
        int a=0;
        for(int i=0;i<nums.size();++i)
        {
            if(c==3)
            a+=find(nums,c-1,nums[i]);
            else
            a+=find(nums,c-1,an&nums[i]);
        }
        return dp[c][an]=a;
    }
    int countTriplets(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return find(nums,3,0);
    }
};