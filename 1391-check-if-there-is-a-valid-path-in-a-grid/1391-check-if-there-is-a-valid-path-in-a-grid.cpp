class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            vis[i][j] = 1;
            
            if(i==n-1&&j==m-1) return true;
            if(grid[i][j] == 1)
            {
                if(j-1>=0 && !vis[i][j-1] && (grid[i][j-1]==4 || grid[i][j-1] == 1 || grid[i][j-1]==6))
                q.push({i,j-1});
                if(j+1<m && !vis[i][j+1]&& (grid[i][j+1]==3 || grid[i][j+1] == 1 || grid[i][j+1]==5))
                q.push({i,j+1});
            }
            if(grid[i][j] == 2)
            {
                if(i-1>=0 && !vis[i-1][j]&& (grid[i-1][j]==2 || grid[i-1][j] == 3 || grid[i-1][j]==4))
                q.push({i-1,j});
                if(i+1<n && !vis[i+1][j]&& (grid[i+1][j]==2 || grid[i+1][j] == 5 || grid[i+1][j]==6))
                q.push({i+1,j});
            }
            if(grid[i][j] == 3)
            {
                if(j-1>=0 && !vis[i][j-1] && (grid[i][j-1]==4 || grid[i][j-1] == 1 || grid[i][j-1]==6))
                q.push({i,j-1});
                if(i+1<n && !vis[i+1][j] && (grid[i+1][j]==2 || grid[i+1][j] == 5 || grid[i+1][j]==6))
                q.push({i+1,j});
            }
            if(grid[i][j] == 4)
            {
                if(j+1<m && !vis[i][j+1]&& (grid[i][j+1]==3 || grid[i][j+1] == 1 || grid[i][j+1]==5))
                q.push({i,j+1});
                if(i+1<n && !vis[i+1][j]&& (grid[i+1][j]==2 || grid[i+1][j] == 5 || grid[i+1][j]==6))
                q.push({i+1,j});
            }
            if(grid[i][j] == 5)
            {
                if(j-1>=0 && !vis[i][j-1]&& (grid[i][j-1]==4 || grid[i][j-1] == 1 || grid[i][j-1]==6))
                q.push({i,j-1});
                if(i-1>=0 && !vis[i-1][j]&& (grid[i-1][j]==2 || grid[i-1][j] == 3 || grid[i-1][j]==4))
                q.push({i-1,j});
            }
            if(grid[i][j] == 6)
            {
                if(j+1<m && !vis[i][j+1]&&(grid[i][j+1]==3 || grid[i][j+1] == 1 || grid[i][j+1]==5))
                q.push({i,j+1});
                if(i-1>=0 && !vis[i-1][j]&& (grid[i-1][j]==2 || grid[i-1][j] == 3 || grid[i-1][j]==4))
                q.push({i-1,j});
            }
            cout << q.front().first << " " << q.front().second << endl;
        }
        return false;
    }
};