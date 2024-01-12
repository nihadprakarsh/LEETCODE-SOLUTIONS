class Solution {
public:
    map<int,int> dp;
    int minOperations(int n) {

        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(dp.count(n)) return dp[n];

       long long i=1;
       while(i*2 < n)
        i *= 2;

      return dp[n]=1 + min(minOperations(n - i),minOperations(2*i - n));
    }
};