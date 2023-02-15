class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int c=1;
        map<char,int> m;
        vector<int> v;
        for(auto &it:pattern)
        {
            if(m.count(it))
            v.push_back(m[it]);
            else
            {
                m[it]=c;
                v.push_back(c);
                c++;
            }
        }
        for(auto &str:words)
        {
            c=1;
            map<char,int> m1;
            vector<int> temp;
            for(auto &it:str)
            {
                if(m1.count(it))
                temp.push_back(m1[it]);
                else
                {
                    m1[it]=c;
                    temp.push_back(c);
                    c++;
                }
            }
            if(temp==v)
            ans.push_back(str);
        }
        return ans;
    }
};