class Solution {
public:
    int ans =0 ;
    void find(string &s, int ind, unordered_set<string>&st,string temp)
    {
        if(ind == s.size()-1)
        {
            temp.push_back(s[ind]);
            if(!st.count(temp))
            {
                st.insert(temp);
                int sz = st.size();
                for(auto it : st)
                // cout << it << " ";
                // cout << endl;
                ans = max(sz,ans);
                st.erase(temp);
            }
            temp.pop_back();
            return;
        }
        temp.push_back(s[ind]);
        if(!st.count(temp))
        {
            st.insert(temp);
            string temp1 = "";
            find(s, ind+1, st, temp1);
            st.erase(temp);
        }
        
        find(s, ind+1, st, temp);
        temp.pop_back();
    }
    
    
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        string temp = "";
        find(s,0,st,temp);
        return ans;
    }
};