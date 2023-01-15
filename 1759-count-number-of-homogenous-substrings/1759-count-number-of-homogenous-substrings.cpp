class Solution {
public:
    int countHomogenous(string s) {
        map<char,int> m;
        vector<int> dp(s.size(),0);
        int i=0,j=0,ans=0,mod=1e9+7;
        while(j<s.size())
        {
            m[s[j]]++;
            while(m.size()>1 && i<j)
            {
                m[s[i]]--;
                if(m[s[i]]==0) m.erase(s[i]);
                i++;
            }
            int cnt=1;
            if(j-1>=0 && s[j-1]==s[j])
            cnt+=dp[j-1];
            dp[j]=cnt;
            ans=(ans+cnt)%mod;
            j++;
        }
        return ans%mod;
    }
};