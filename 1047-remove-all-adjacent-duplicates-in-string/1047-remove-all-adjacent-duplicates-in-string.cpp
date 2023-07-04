class Solution {
public:
    string removeDuplicates(string s) {
        stack<pair<char,int>> st;
        for(auto &it:s)
        {
            char ch = it;
            if(!st.empty() && st.top().first == ch)
                st.top().second++;
            else
                st.push({ch,1});
            if(st.top().second == 2)
                st.pop();
        }
        
        string str = "";
        while(!st.empty()){
            auto sz = st.top().second;
            while(sz--){
                str.push_back(st.top().first);
            }
            st.pop();
        }
        
        reverse(begin(str),end(str));
        return str;
    }
};