class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        long long int i =0, j =0, sum = 0, ans =0 ;
        while(j < nums.size())
        {
            sum+=nums[j];
            while((nums[j]*(j-i+1)*1LL) > (sum+k+0LL) && i<j)
                sum-=nums[i++];
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};