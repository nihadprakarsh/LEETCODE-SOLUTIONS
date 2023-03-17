class Solution {
public:
    int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;++i)
        v.push_back({efficiency[i],speed[i]});
        sort(v.rbegin(),v.rend());
        long long s=0,res=0;
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<n;++i)
        {
            s+=v[i].second;
            q.push(v[i].second);
            if(q.size()>k)
            {
                s-=q.top();
                q.pop();
            }
            res=max(res,s*v[i].first);
        }
        return res%mod;
    }
};