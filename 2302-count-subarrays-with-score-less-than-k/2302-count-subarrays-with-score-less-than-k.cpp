class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int i=0, j=0,sum =0,ans=0;
        while(j < nums.size())
        {
            sum+=nums[j];
            while(sum*(j-i+1) >= k)
                sum-=nums[i++];
            ans+=(j-i+1);
            j++;
        }
        return ans;
        
    }
};