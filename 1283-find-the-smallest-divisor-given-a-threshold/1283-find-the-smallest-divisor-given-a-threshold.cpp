class Solution {
public:
    bool check(int mid, int threshold, vector<int>&nums)
    {
        int s= 0;
        for(auto &it:nums)
        {
            if(it%mid==0)
            s+=it/mid;
            else
            s+=it/mid+1;
        }
        return s<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=1e6,mid,ans;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(check(mid,threshold,nums))
            {
                high=mid-1;
                ans=mid;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};