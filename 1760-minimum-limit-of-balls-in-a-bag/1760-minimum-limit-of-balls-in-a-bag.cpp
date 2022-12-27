class Solution {
public:
    bool check(int mid,vector<int>&nums,int mo)
    {
        for(int i=0; i< nums.size(); ++i)
        {
            mo-=nums[i]/mid;
            if(nums[i]%mid==0) mo++;
        }
        return mo>=0;
    }
    int minimumSize(vector<int>& nums, int mo) {
        int low=1,high=INT_MAX,mid,ans=0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(check(mid,nums,mo))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};