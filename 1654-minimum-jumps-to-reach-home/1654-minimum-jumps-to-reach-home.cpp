class Solution {
public:
    set<int> st;
    int dp[6005][3] = {{0}};
    int find(int a, int b, int i, int c, int x)
    {
        if(i==x)
            return 0;
        if(i < 0 || i > 6000 || st.count(i))
            return 1e9;
        if(dp[i][c]) return dp[i][c];
        int a1 = 0, b1 = 0;
        dp[i][c] = 1 + find(a,b,i+a,0,x);
        dp[i][c] = min(dp[i][c], c==0? 1 + find(a,b,i-b,1,x) : dp[i][c]);
        return dp[i][c];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(auto it : forbidden)
            st.insert(it);
        int k = find(a, b, 0, 0, x);
        // cout << k << endl;
        return k>=1e9?-1:k;
        
    }
};