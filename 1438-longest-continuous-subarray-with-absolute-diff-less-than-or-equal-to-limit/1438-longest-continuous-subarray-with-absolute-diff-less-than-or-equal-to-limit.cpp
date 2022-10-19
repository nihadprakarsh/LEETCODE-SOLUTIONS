class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int ans = 0, i =0 , j =0;
        while(j < nums.size())
        {
            st.insert(nums[j]);
            while(abs(*st.begin()-*st.rbegin()) > limit)
                st.erase(st.lower_bound(nums[i++]));
            ans = max(j-i+1, ans);
            j++;
        }
        return ans;
    }
};