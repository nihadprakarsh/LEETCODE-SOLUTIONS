bool comp(string&a,string&b)
{
    if(a.size()==b.size())
    return a<b;
    return a.size()<b.size();
}
class Solution {
public:
    int dp[1001][1001];
    bool isSubsequence(string &s, string &t) {
        int i=0,j=0;
        while(j<t.size())
        {
            if(s[i]==t[j])
            i++;
            if(i==s.size()) return 1;
            j++;
        }
        return 0;
    }
    int find(int ind,int prev,vector<string>&words)
    {
        if(ind==words.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int a=0,b=0;
        if(prev==-1||(isSubsequence(words[prev],words[ind]) && words[ind].size()-words[prev].size()==1))
        a=1+find(ind+1,ind,words);
        b=find(ind+1,prev,words);
        return dp[ind][prev+1]=max(a,b);
    }
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        sort(begin(words),end(words),comp);
        return find(0,-1,words);
    }
};