class Solution {
public:
    int ans= 0;
    bool isPallin(string &s)
    {
        int i =0, j=  s.size()-1;
        while(i<j)
        {
            if(s[i] != s[j])
            return false;
            i++;j--;
        }
        return true;
    }
    void dfs(string &s, int ind, string &s1, string &s2)
    {
        if(ind==s.size())
        {
            if(isPallin(s1) && isPallin(s2)){
            int tot = s1.size() * s2.size();
            ans=max(ans,tot);
            }
            return;
        }
        
        s1.push_back(s[ind]);
        dfs(s,ind+1,s1,s2);
        s1.pop_back();
        
        s2.push_back(s[ind]);
        dfs(s,ind+1,s1,s2);
        s2.pop_back();
        
        dfs(s,ind+1,s1,s2);
    }
    int maxProduct(string s) {
        string s1="",s2="";
        dfs(s,0,s1,s2);
        return ans;
    }
};