class Solution {
public:
    typedef pair<int,int> pt;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pt,vector<pt>,greater<pt>> q;
        vector<vector<int>> v;
        for(int i=0;i<tasks.size();++i)
        v.push_back({tasks[i][0],tasks[i][1],i});
        sort(begin(v),end(v));
        long long t=v[0][0];
        vector<int> res;
        int i=0;
        while(i<v.size())
        {
            if(v[i][0]<=t)
            {
                while(i<v.size() && v[i][0]<=t)
                {
                    // cout << tasks[i][1] << endl;
                    q.push({v[i][1],v[i][2]});
                    i++;
                }
                while(!q.empty())
                {
                    res.push_back(q.top().second);
                    // cout << q.top().second << endl;
                    t+=q.top().first;
                    q.pop();
                    while(i<v.size() && v[i][0]<=t)
                    q.push({v[i][1],v[i][2]}),i++;
                    // cout << t << " " << q.top().second << endl;
                }
            }
            else
            {
                t=v[i][0];
                // cout << t << endl;
            }
        }
        return res;
    }
};