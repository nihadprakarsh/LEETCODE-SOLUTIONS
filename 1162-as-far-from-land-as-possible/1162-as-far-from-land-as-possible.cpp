class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int res=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                q.push({i,j});
            }
        }
        while(!q.empty())
        {
            res++;
            int sz=q.size();
            while(sz--)
            {
                auto i = q.front().first;
                auto j = q.front().second;
                q.pop();
                int drow[]={0,1,0,-1};
                int dcol[]={1,0,-1,0};
                for(int k=0;k<4;++k)
                {
                    int nrow=i+drow[k];
                    int ncol=j+dcol[k];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==0)
                    {
                        grid[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return res==1?-1:res-1;
    }
};