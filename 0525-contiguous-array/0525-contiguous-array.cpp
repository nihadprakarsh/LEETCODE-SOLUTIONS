class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();++i)
        if(nums[i]==0) nums[i]=-1;
        int ans=0,s=0;
        map<int,int> m;
        m[0]=-1;
        for(int i=0;i<nums.size();++i)
        {
            s+=nums[i];
            if(m.count(s))
            ans=max(ans,i-m[s]);
            if(!m.count(s))
            m[s]=i;
        }
        return ans;
    }
};