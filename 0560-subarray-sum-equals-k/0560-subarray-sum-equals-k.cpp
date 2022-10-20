class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        int i=0, j= 0,sum=0,res=0;
        while(j < nums.size())
        {
            sum+=nums[j];
            if(sum == k)
                res++;
            if(m.count(sum-k))
                res+=m[sum-k];
            m[sum]++;
            j++;
        }
        return res;
    }
};