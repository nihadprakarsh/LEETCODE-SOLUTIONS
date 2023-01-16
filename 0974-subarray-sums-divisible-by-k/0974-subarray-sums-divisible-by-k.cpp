class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>m;
        m[0]=1;
        int s=0,ans=0;
        for(int i=0;i<nums.size();++i)
        {
            s+=nums[i];
            int rem=s%k;
            if(rem<0) rem+=k;
            if(m.count(rem))
            ans+=m[rem];
            m[rem]++;
        }
        return ans;
    }
};