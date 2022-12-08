class Solution {
public:
    int numSplits(string s) {
        vector<int> prefix(s.size()),suffix(s.size());
        set<char> st;
        for(int i= 0; i< s.size(); ++i)
        {
            st.insert(s[i]);
            prefix[i] = st.size();
        }
        
        st.clear();
        for(int i = s.size()-1; i>=0; --i)
        {
            st.insert(s[i]);
            suffix[i] = st.size();
        }
        
        int count  = 0;
        for(int i =0 ; i < s.size()-1; ++i)
        {
            if(prefix[i] == suffix[i+1])
            count++;
        }
        return count;
    }
};