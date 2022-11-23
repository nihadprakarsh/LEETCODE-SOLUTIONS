class Solution {
public:
    int dp[20];
    unsigned long int catalan(unsigned int n) 
    { 
        // Base case 
        if (n <= 1) return 1; 
        if(dp[n] != -1) return dp[n];
       
        unsigned long int res = 0; 
        for (int i=0; i<n; i++) 
            res += catalan(i)*catalan(n-i-1); 

        return dp[n] = res; 
    }
    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        return catalan(n);
    }
};