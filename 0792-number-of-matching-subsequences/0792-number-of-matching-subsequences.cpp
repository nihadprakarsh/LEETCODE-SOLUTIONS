class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,set<int>> m;
        for(int i=0;i<s.size();++i)
        m[s[i]].insert(i);
        int res=0;
        for(auto &it:words)
        {
            int i = -1,j=0;
            for(auto &ch:it)
            {
                if(m[ch].upper_bound(i) != m[ch].end())
                {
                    j++;
                    i=*m[ch].upper_bound(i);
                    if(j==it.size())
                    {
                        res++;
                        break;
                    }
                }
            }
        }
        return res;
    }
};