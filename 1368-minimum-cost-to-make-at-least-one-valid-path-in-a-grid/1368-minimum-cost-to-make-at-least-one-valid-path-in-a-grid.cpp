class Solution {
public:
    typedef pair<int,pair<int,int>> pt;
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        vector<vector<int>> vist(n,vector<int>(m,0));
        dist[0][0] = 0;
        vist[0][0] = 1;
        priority_queue<pt,vector<pt>,greater<pt>> q;
        int moves[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        q.push({0,{0,0}});
        while(!q.empty())
        {
            int steps = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            vist[r][c] = 1;
            q.pop();
            
//             vis[grid[r][c]-1] = 1;
            for(int k =0 ; k < 4; ++k)
            {
                int nr = r + moves[k][0];
                int nc = c + moves[k][1];
                if(nr<n&&nc<m&&nr>=0&&nc>=0&&!vist[nr][nc])
                            {
                                int cost = (grid[r][c]!=k+1);
                                if(dist[nr][nc]>(dist[r][c]+cost))
                                {
                                    dist[nr][nc] = dist[r][c] + cost;
                                    q.push({dist[nr][nc],{nr,nc}});
                                }
                            }
            }
        }
        
        return dist[n-1][m-1];
    }
};