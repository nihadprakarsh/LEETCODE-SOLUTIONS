class Solution {
public:
    int dp[1001][1001];
    bool Pallin(int i, int j, string&s)
    {
        if(i>=j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = Pallin(i+1,j-1,s);
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));
        int ans = 0; string fv = "";
        for(int i =0 ; i < s.size(); ++i)
        {
            string temp = "";
            for(int j = i; j < s.size(); ++j)
            {
                temp.push_back(s[j]);
                if(Pallin(i,j,s))
                {
                    if(ans < j-i+1)
                    {
                        ans=j-i+1;
                        fv = temp;
                    }
                }
            }
        }
        return fv;
    }
};