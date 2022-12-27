class Solution {
public:
    bool check(int mid,vector<int>&nums,int k)
    {
        int i=0,j=0,c=0;
        while(j<nums.size())
        {
            if(nums[j]==0) c++;
            if(j-i+1==mid)
            {
                if(c<=k)
                return true;
                if(nums[i]==0) c--;
                i++;
            }
            j++;
        }
        return false;
    }
    int longestOnes(vector<int>& nums, int k) {
        int low=0,high=nums.size()+1,mid,ans=0;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(check(mid,nums,k))
            {
                low=mid+1;
                ans=mid;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};