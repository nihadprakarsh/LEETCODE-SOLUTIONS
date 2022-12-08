class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, 0, sizeof(dp));
        for(int ind1 = text1.size()-1; ind1 >=0 ; --ind1)
        {
            for(int ind2 = text2.size()-1; ind2>=0; ind2--)
            {
                int a =0 , b =0 ;
                if(text1[ind1] == text2[ind2])
                a = 1 + dp[ind1+1][ind2+1];
                b = max(dp[ind1+1][ind2],dp[ind1][ind2+1]);
                dp[ind1][ind2] = max(a,b);
            }
        }
        return dp[0][0];
    }
};