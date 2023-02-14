class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        vector<long long> dp(p.size(),1);
        for(int i=1;i<p.size();++i)
        {
            if(p[i-1]-p[i]==1)
            dp[i]+=dp[i-1];
        }
        long long s=0;
        for(auto &it:dp) s+=it;
        return s;
    }
};