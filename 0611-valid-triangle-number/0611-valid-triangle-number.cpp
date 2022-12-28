class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        int c=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                auto it= lower_bound(begin(nums)+j+1,end(nums),nums[i]+nums[j])-begin(nums)-1;
                c+=it-j;
            }
        }
        return c;
    }
};