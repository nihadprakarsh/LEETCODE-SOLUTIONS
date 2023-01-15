class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        map<int,int>m;
        int z=0,ans=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==0)
            {
                z++;
                m[z]=i;
            }
            if(z>k)
            ans=max(ans,i-m[z-k]);
            else
            ans=max(ans,i+1);
        }
        return ans;
    }
};