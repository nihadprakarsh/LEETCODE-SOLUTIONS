class Solution {
public:
    bool find(string &s,set<string>&st)
    {
        for(int i=1;i<s.size();++i)
        {
            string a=s.substr(0,i);
            string b=s.substr(i);
            // cout << a << " " << b << endl;
            if((st.count(a) && st.count(b)) || (st.count(a) && find(b,st)))
            return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string> st(begin(words),end(words));
        vector<string> ans;
        for(auto &word:words)
        {
            if(find(word,st))
            ans.push_back(word);
        }
        return ans;
    }
};