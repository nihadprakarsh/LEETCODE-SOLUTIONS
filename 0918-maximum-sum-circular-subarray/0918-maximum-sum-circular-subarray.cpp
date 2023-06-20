class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        bool posFlag = false;
        for(auto &it:nums) if(it>=0) posFlag=true;
        if(!posFlag) return *max_element(begin(nums),end(nums));
        int pos=0,neg=1e9,sum=0,arrSum = accumulate(begin(nums),end(nums),0);
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            pos=max(pos,sum);
            if(sum<0)
                sum=0;
        }
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            neg=min(neg,sum);
            if(sum>0) sum =0;
        }
        int s1 = arrSum - neg;
        return max(pos,s1);
    }
};