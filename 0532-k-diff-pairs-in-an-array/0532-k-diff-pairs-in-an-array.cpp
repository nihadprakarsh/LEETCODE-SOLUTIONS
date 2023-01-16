class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;
        map<int,int> m;
        set<vector<int>> st;
        for(int i=0;i<nums.size();++i)
        {
            if(m.count(nums[i]+k))
            {
                int m1=min(nums[i]+k,nums[i]);
                int m2=max(nums[i]+k,nums[i]);
                st.insert({m1,m2});
            }
            if(m.count(nums[i]-k))
            {
                int m1=min(nums[i]-k,nums[i]);
                int m2=max(nums[i]-k,nums[i]);
                st.insert({m1,m2});
            }
            m[nums[i]]++;
        }
        return st.size();
    }
};