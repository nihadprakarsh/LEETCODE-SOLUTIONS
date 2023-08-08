class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int freshOrange = 0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j] == 1)
                    freshOrange++;
            }
        }
        
        int count = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto i = q.front().first;
                auto j = q.front().second;
                q.pop();
                int drow[]={0,1,0,-1};
                int dcol[]={1,0,-1,0};
                for(int x=0;x<4;++x)
                {
                    int nrow = i+drow[x];
                    int ncol = j+dcol[x];
                    if(nrow>=0&&nrow<grid.size()&&ncol>=0&&ncol<grid[0].size()&&grid[nrow][ncol]==1)
                    {
                        grid[nrow][ncol]=2;
                        q.push({nrow,ncol});
                    }
                }
            }
            count++;
        }
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
                if(grid[i][j] == 1)
                    return -1;
        }
        if(freshOrange > 0)
            return count-1;
        return 0;
    }
};