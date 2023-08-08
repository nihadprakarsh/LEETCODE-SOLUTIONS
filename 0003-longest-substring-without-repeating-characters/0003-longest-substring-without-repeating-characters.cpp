class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,res=0;
        map<int,int> m;
        while(j<s.size())
        {
            m[s[j]]++;
            while(m[s[j]]>1)
            {
                m[s[i]]--;
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};