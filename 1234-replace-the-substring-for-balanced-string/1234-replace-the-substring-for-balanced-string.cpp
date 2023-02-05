class Solution {
public:
    bool isBalanced(map<char,int>&m,string&s)
    {
        for(auto &it:m)
        if(it.second>s.size()/4) return false;
        return true;
    }
    int balancedString(string s) {
        map<char,int> m;
        for(auto &it:s) m[it]++;
        int i=0,j=0,ans=INT_MAX;
        if(isBalanced(m,s)) return 0;
        while(j<s.size())
        {
            m[s[j]]--;
            if(isBalanced(m,s))
            {
                ans=min(ans,j-i+1);
                while(i<=j)
                {
                    m[s[i]]++;
                    i++;
                    if(isBalanced(m,s))
                    ans=min(ans,j-i+1);
                    else
                    break;
                }
            }
           j++;
        }
        return ans;
    }
};