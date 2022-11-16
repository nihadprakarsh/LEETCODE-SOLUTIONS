class Solution {
public:
     int minCost(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visi(n,vector<int> (m));
    vector<vector<int>> dis(n,vector<int> (m,INT_MAX));
    int moves[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    dis[0][0] = 0;
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
    pq.push({0,{0,0}});
    visi[0][0] = 1;
    while(pq.size())
    {
        pair<int,pair<int,int>> mini = pq.top();
        int r = mini.second.first;
        int c= mini.second.second;
        pq.pop();
        visi[r][c] = 1;
        for(int k=0;k<4;k++)
        {
            int nr = r + moves[k][0];
            int nc = c + moves[k][1];
            if(nr<n&&nc<m&&nr>=0&&nc>=0&&!visi[nr][nc])
            {
                int cost = (grid[r][c]!=k+1);
                if(dis[nr][nc]>(dis[r][c]+cost))
                {
                    dis[nr][nc] = dis[r][c] + cost;
                    pq.push({dis[nr][nc],{nr,nc}});
                }
            }
        } 
    }
    return dis[n-1][m-1];
    }
};