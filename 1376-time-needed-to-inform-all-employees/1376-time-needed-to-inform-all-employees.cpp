class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0; i < manager.size(); ++i)
        {
            if(i != headID)
            adj[manager[i]].push_back(i);
        }
        vector<int> vis(n,0);
        vis[headID] = 1;
        int ans = 0;
        queue<pair<int,int>> q;
        q.push({headID,0});
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto node = q.front().first;
                int time = q.front().second;
                q.pop();
                for(auto nodes : adj[node])
                {
                    int dur = time + informTime[node];
                    ans = max(ans, dur);
                    q.push({nodes,dur});
                }
            }
        }
        return ans;
    }
};