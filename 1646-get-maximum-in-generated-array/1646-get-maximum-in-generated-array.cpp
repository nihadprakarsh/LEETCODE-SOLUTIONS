class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        map<int,int>m;
        m[0]=0,m[1]=1;
        for(int i=0;i<=n;++i)
        {
            int ind = 2*i+1;
            int ind2= 2*i;
            if(ind2<=n && !m.count(ind2))
                m[ind2]=m[i];
            if(ind<=n && !m.count(ind))
                m[ind]=m[i]+m[i+1];
        }
        int ans = 0;
        for(auto &it:m)
        {
            // cout << it.second << endl;
            ans=max(ans,it.second);
        }
        return ans;
    }
};