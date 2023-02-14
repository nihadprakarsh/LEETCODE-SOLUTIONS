class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<pair<int,int>> dp1(n,{1e9,1e9}),dp2(n,{1e9,1e9});
        int a=0,b=0,lb=-1;
        for(int i=0;i<s.size();++i)
        {
            dp1[i]={a,b};
            if(s[i]=='a') a++;
            else b++;
        }
        a=0,b=0;
        for(int i=s.size()-1;i>=0;--i)
        {
            dp2[i]={a,b};
            if(s[i]=='a') a++;
            else b++;
            if(s[i]=='b' && lb==-1) lb=i; 
        }
        int ans=INT_MAX,prev=-1;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='b')
            {
                int cnt=dp2[i].first;
                if(prev!=-1) cnt+=dp1[i].first-dp1[prev].first;
                if(cnt) ans=min(ans,cnt);
                if(prev==-1) prev=i;
            }
            else if(s[i]=='a')
            {
                int cnt=dp1[i].second;
                if(lb!=-1) cnt+=dp2[i].first;
                if(cnt) ans=min(ans,cnt);
            }
        }
        return ans==INT_MAX?0:ans;
    }
};