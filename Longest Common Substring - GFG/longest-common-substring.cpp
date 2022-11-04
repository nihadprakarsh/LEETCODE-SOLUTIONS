//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int ans = 0;
    int dp[1000][1000];
    int find(string &s1, string &s2, int i, int j, int n, int m){
        if(i == n || j == m)
        return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = 0;
        if(s1[i] == s2[j])
        dp[i][j] = 1 + find(s1,s2,i+1,j+1,n,m);
        else
        dp[i][j] = 0;
        int b = find(s1,s2,i+1,j,n,m);
        int c = find(s1,s2,i,j+1,n,m);
        ans = max(ans,dp[i][j]);
        return dp[i][j];
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        memset(dp, -1, sizeof(dp));
        int k = find(S1,S2,0,0,n,m);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends