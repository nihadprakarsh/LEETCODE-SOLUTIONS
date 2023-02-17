class Solution {
public:
    int dp[1001][1001];
    int find(string&a,string&b,int i,int j)
    {
        if(i==a.size() || j==b.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a1=0;
        if(a[i]==b[j])
        a1=1+find(a,b,i+1,j+1);
        a1=max(a1,max(find(a,b,i+1,j),find(a,b,i,j+1)));
        return dp[i][j]=a1;
    }
    int longestPalindromeSubseq(string s) {
        string text1 = s, text2 = s;
        reverse(begin(text2), end(text2));
        memset(dp,-1,sizeof(dp));
        return find(text1,text2,0,0);
    }
};