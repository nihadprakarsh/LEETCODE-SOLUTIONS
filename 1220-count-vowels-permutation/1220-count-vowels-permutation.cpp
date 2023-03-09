class Solution {
public:
    int mod=1e9+7;
    int dp[2*10000+2][28];
    int find(int n, int prev)
    {
        if(n==0)
        return 1;
        if(dp[n][prev+1]!=-1) return dp[n][prev+1];
        int a=0;
        char ch[]={'a','e','i','o','u'};
        for(int i=0;i<5;++i)
        {
            if(prev==-1)
            a=(a+find(n-1,ch[i]-'a'))%mod;
            else if(prev+'a'=='a' && ch[i]=='e')
            a=(a+find(n-1,ch[i]-'a'))%mod;
            else if(prev+'a'== 'e' && (ch[i]=='a'|| ch[i]=='i'))
            a=(a+find(n-1,ch[i]-'a'))%mod;
            else if(prev+'a'=='i' && ch[i]!='i')
            a=(a+find(n-1,ch[i]-'a'))%mod;
            else if(prev+'a' == 'o' && (ch[i]=='u'|| ch[i]=='i'))
            a=(a+find(n-1,ch[i]-'a'))%mod;
            else if(prev+'a'=='u' && ch[i]=='a')
            a=(a+find(n-1,ch[i]-'a'))%mod;
        }
        return dp[n][prev+1]=a%mod;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        return find(n,-1);
    }
};