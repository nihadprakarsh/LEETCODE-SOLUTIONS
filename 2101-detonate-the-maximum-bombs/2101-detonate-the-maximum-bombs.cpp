class Solution {
public:
    typedef long long int ll;
    ll maxBomb = 0;
    void getAdj(vector<ll> adj[], vector<vector<int>> &bombs)
    {
        for(int i=0; i < bombs.size(); ++i)
        {
            for(int j =0; j < bombs.size(); ++j)
            {
                if(i!=j)
                {
                    ll ib1 = bombs[i][0];
                    ll jb1 = bombs[i][1];
                    ll rb1 = bombs[i][2];
                    ll ib2 = abs(ib1-bombs[j][0]);
                    ll jb2 = abs(jb1-bombs[j][1]);
                    ll rb2 = bombs[j][2];
                    if(ib2*ib2 + jb2*jb2 <= rb1*rb1)
                    adj[i].push_back(j);
                }
            }
        }
    }
    
    void bfs(ll i, vector<ll> adj[], ll n)
    {
        vector<ll> vis(n,0);
        vis[i] = 1;
        ll count =0 ;
        queue<ll> q;
        q.push(i);
        while(!q.empty())
        {
            ll sz = q.size();
            while(sz--)
            {
                auto node = q.front();
                q.pop();
                for(auto nodes : adj[node])
                {
                    if(!vis[nodes]){
                    vis[nodes] = 1;
                    count++;
                    q.push(nodes);
                    }
                }
            }
        }
        maxBomb = max(maxBomb,1+count);
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        ll n = bombs.size();
        vector<ll> adj[n];
        getAdj(adj, bombs);        
        for(ll i =0; i < n; ++i)
        bfs(i,adj,n);
        return maxBomb;
    }
};