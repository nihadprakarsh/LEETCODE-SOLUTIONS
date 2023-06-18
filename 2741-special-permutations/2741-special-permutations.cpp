class Solution {
public:
    int mod = 1e9+7;
    int dp[15][15][20000];
    long long find(vector<int>&nums,int ind,int prev,int vis)
    {
        if(ind == nums.size()) return 1;
        if(dp[ind][prev+1][vis]!=-1) return dp[ind][prev+1][vis];
        long long n = nums.size();
        long long a = 0;
        for(int i=0;i<n;++i)
        {
            if(prev==-1 or ((((1<<i)&vis)==0) and (nums[prev]%nums[i]==0 or (nums[i]%nums[prev]==0))))
            {
                int temp = vis;
                vis=((1<<i)|temp);
                a=(a+find(nums,ind+1,i,vis))%mod;
                vis=temp;
            }
        }
        return dp[ind][prev+1][vis]=a;
    }
    int specialPerm(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return find(nums,0,-1,0)%mod;
    }
};