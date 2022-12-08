class Solution {
public:
    int find(string &s, int &k, int ind, int prev, vector<vector<int>>&dp)
    {
        if(ind == s.size()) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int a = 0, b= 0 ;
        if(prev == -1 || abs((s[ind]-'a') - prev) <= k)
        a = 1 + find(s,k,ind+1,s[ind]-'a',dp);
        b = find(s,k,ind+1,prev,dp);
        return dp[ind][prev+1] = max(a,b);
    } 
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size()+1, vector<int>(30,-1));
        return find(s,k,0,-1,dp);
    }
};