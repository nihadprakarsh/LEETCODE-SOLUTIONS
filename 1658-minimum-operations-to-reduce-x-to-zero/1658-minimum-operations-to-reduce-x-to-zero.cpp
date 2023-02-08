class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s=0,i=0,j=0,s1=accumulate(begin(nums),end(nums),0),ans=INT_MIN;
        while(j<nums.size())
        {
            s+=nums[j];
            while(s>s1-x && i<=j)
            s-=nums[i++];
            if(s==s1-x)
            ans=max(ans,j-i+1);
            j++;
        }
        return ans==INT_MIN?-1:nums.size()-ans;
    }
};