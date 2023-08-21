class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        int i=0,j=0;
        vector<int> v;
        while(j<nums.size())
        {
            st.insert(nums[j]);
            if(j-i+1==k)
            {
                v.push_back(*st.rbegin());
                st.erase(st.lower_bound(nums[i++]));
            }
            j++;
        }
        return v;
    }
};