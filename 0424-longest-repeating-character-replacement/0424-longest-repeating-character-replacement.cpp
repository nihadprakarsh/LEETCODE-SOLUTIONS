class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> m;
        int i=0,j=0,ans=0,mx=0;
        while(j<s.size())
        {
            m[s[j]]++;
            mx=max(mx,m[s[j]]);
            while(j-i-mx+1>k)
            m[s[i++]]--;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};