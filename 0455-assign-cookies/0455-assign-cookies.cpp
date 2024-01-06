class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        multiset<int> st(begin(s),end(s));
        sort(begin(g),end(g));
        int ans=0;
        for(auto i:g)
        {
            if(st.count(i))
            {
                ans++;
                st.erase(st.lower_bound(i));
            }
            else
            {
                auto it = st.upper_bound(i);
                if(it == st.end())
                    continue;
                else
                {
                    ans++;
                    st.erase(it);
                }
            }
        }
        return ans;
    }
};