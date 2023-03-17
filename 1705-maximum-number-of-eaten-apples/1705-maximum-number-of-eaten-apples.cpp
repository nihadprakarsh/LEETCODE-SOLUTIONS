class Solution {
public:
    typedef pair<int,int> pt;
    int eatenApples(vector<int>& apples, vector<int>& d) {
        int ans=0,i=0;
        priority_queue<pt,vector<pt>,greater<pt>> q;
        int n = apples.size();
        for(;i<n;++i)
        {
            q.push({d[i]+i,apples[i]});
            while(!q.empty() && q.top().first<=i) q.pop();
            if(!q.empty())
            {
                auto front=q.top().second;
                auto days=q.top().first;
                q.pop();
                front--;
                if(front) q.push({days,front});
                ans++;
                // cout << ans << endl;
            }
        }
        while(!q.empty())
        {
            while(!q.empty() && q.top().first<=i) q.pop();
            if(!q.empty()){
            auto front=q.top().second;
            auto days=q.top().first;
            q.pop();
            front--;
            ans++;
            if(front) q.push({days,front});
            i++;
            }
        }
        return ans;
    }
};