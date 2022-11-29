class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int i = 1;
        for(auto it:nums)
        {
            if(it > i)
            return i;
            if(it == i)
            i++;
        }
        return i;
    }
};