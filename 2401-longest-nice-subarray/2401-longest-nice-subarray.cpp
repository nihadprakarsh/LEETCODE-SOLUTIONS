class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i =0, j =0, ans= 0,sum=0;
        while(j < nums.size())
        {
            while((sum&nums[j])!=0)
                sum^=nums[i++];
            sum|=nums[j];
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};