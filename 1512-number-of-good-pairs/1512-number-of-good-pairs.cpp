class Solution {
public:
    int arr[101];
    int numIdenticalPairs(vector<int>& nums) {
        int s=0;
        for(int i=0;i<nums.size();++i)
        arr[nums[i]]++,s+=arr[nums[i]]-1;
        return s;
    }
};