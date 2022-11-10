//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>>&grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto x = q.front().first;
            auto y = q.front().second;
            q.pop();
            int drow[] = {0,1,0,-1,1,-1,1,-1};
            int dcol[] = {1,0,-1,0,1,-1,-1,1};
            for(int ind= 0; ind < 8; ++ind){
                int nrow = x + drow[ind];
                int ncol = y + dcol[ind];
                if(nrow >=0 && nrow < grid.size() && ncol >=0 && ncol < grid[0].size() &&
                grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
                
            }
        }
}
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size(), m = grid[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i=0; i < n; ++i){
            for(int j= 0; j < m; ++j){
                v[i][j] = grid[i][j] - '0';
            }
        }
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i < n; ++i){
            for(int j =0; j < m; ++j){
                if(v[i][j] == 1 && !vis[i][j]){
                    vis[i][j] = 1;
                    ans++;
                    bfs(i,j,vis,v);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends