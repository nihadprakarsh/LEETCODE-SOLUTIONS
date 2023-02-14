class Solution {
public:
    int dp[502][502];
    int find(int ind,int limit,vector<int>& nums1, vector<int>& nums2)
    {
        if(ind==nums1.size()) return 0;
        if(dp[ind][limit+1]!=-1) return dp[ind][limit+1];
        int a=0;
        for(int i=limit+1;i<nums2.size();++i)
        {
            if(nums1[ind]==nums2[i])
            a=max(a,1+find(ind+1,i,nums1,nums2));
        }
        a=max(a,find(ind+1,limit,nums1,nums2));
        return dp[ind][limit+1]=a;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return find(0,-1,nums1,nums2);
    }
};