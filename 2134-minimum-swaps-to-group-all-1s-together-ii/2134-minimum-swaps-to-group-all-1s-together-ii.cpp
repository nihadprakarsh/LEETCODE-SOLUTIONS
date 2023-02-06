class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int c=0; for(auto &it:nums) c+=it==1;
        nums.insert(nums.end(), nums.begin(), nums.end());
        int i=0,j=0,k=0,ans=INT_MAX;
        while(j<nums.size())
        {
            if(nums[j]==0) k++;
            if(j-i+1==c)
            {
                ans=min(ans,k);
                if(nums[i]==0) k--;
                i++;
            }
            j++;
        }
        return ans==INT_MAX?0:ans;
    }
};