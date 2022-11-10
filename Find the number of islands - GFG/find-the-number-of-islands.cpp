//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>>&grid){
        int drow[] = {0,1,0,-1,1,-1,1,-1};
        int dcol[] = {1,0,-1,0,1,-1,-1,1};
        for(int ind= 0; ind < 8; ++ind){
            int nrow = i + drow[ind];
            int ncol = j + dcol[ind];
            if(nrow >=0 && nrow < grid.size() && ncol >=0 && ncol < grid[0].size() &&
            grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                vis[nrow][ncol] = 1;
                dfs(nrow,ncol,vis,grid);
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
                    dfs(i,j,vis,v);
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