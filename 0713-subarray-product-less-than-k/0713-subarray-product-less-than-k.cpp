class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0, j =0,p=1,ans=0;
        while(j < nums.size())
        {
            p*=nums[j];
            while(p >= k && i <= j)
                p/=nums[i++];
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};