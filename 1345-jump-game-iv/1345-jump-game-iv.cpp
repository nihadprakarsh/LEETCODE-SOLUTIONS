class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int vis[n]; memset(vis,0,sizeof(vis));
        map<int,vector<int>> m;
        for(int i = 0; i < arr.size(); ++i) m[arr[i]].push_back(i);
        queue<int> q; q.push(0);
        vis[0] = 1;
        int steps = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto node = q.front(); q.pop();
                if(node == n-1) return steps;
                vector<int> &temp = m[arr[node]];
                temp.push_back(node+1); temp.push_back(node-1);
                for(auto &it : temp)
                {
                    if(it >=0 && it < n && !vis[it])
                    {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
                temp.clear();
            }
            steps++;
        }
        return -1;
    }
};