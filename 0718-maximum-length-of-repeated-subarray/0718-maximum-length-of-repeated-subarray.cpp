class Solution {
public:
    int dp[1000][1000];
    int ans =0 ;
    int find(vector<int>&nums1, vector<int>&nums2, int i, int j, int n, int m){
        if(i == n || j == m)
        return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = 0;
        if(nums1[i] == nums2[j])
        dp[i][j] = 1 + find(nums1,nums2,i+1,j+1,n,m);
        else
        dp[i][j] = 0;
        int b = find(nums1,nums2,i+1,j,n,m);
        int c = find(nums1,nums2,i,j+1,n,m);
        ans = max(ans,dp[i][j]);
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        int k = find(nums1,nums2,0,0,nums1.size(),nums2.size());
        return ans;
    }
};