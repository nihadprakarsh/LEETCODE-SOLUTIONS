class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,ans=0,c=0;
        while(j<nums.size())
        {
            if(nums[j]==0) c++;
            while(c>k) c-=nums[i++]==0;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};