class Solution {
public:
    int dp[1001][1001];
    int find(string &text1, string &text2, int ind1, int ind2)
    {
        if(ind1 == text1.size() || ind2 == text2.size()) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int a =0 , b =0 ;
        if(text1[ind1] == text2[ind2])
        a = 1 + find(text1,text2,ind1+1,ind2+1);
        b = max(find(text1,text2,ind1+1,ind2),find(text1,text2,ind1,ind2+1));
        return dp[ind1][ind2] = max(a,b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return find(text1,text2,0,0);
    }
};