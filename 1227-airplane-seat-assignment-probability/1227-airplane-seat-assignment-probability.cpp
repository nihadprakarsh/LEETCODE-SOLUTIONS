class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n >= 2) return 0.50000;
        double ans = 1/(double)n;
        return ans;
    }
};