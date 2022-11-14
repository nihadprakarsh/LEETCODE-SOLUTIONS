//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0; i < grid.size(); ++i){
            for(int j =0; j < grid[0].size(); ++j){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        
        
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            for(int i=0; i < sz; ++i){
                auto ind = q.front();
                q.pop();
                int drow[] = {0,1,0,-1};
                int dcol[] = {1,0,-1,0};
                for(int j = 0; j < 4; ++j){
                    int nrow = ind.first + drow[j];
                    int ncol = ind.second + dcol[j];
                    if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        
        for(int i=0; i < n; ++i){
            for(int j =0; j < m; ++j)
            if(grid[i][j] == 1) return -1;
        }
        return ans-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends