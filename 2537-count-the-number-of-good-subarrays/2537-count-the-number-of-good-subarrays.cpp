class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
       long long i=0,j=0,s=0,ans=0;
        map<long long, long long> m;
        while(j<nums.size())
        {
            m[nums[j]]++;
            s+=m[nums[j]]-1;
            while(i<=j && s>=k)
            {
                ans+=nums.size()-j;
                s-=m[nums[i]]-1;
                m[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};