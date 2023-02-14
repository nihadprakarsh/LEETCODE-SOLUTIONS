class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        vector<long long> a(p.size(),1);
        for(int i=1;i<p.size();++i)
        {
            if(p[i-1]-p[i]==1)
            a[i]+=a[i-1];
        }
        long long s=0;
        for(auto &it:a) s+=it;
        return s;
    }
};