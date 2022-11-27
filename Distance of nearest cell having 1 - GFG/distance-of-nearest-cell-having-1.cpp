//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int bfs(int i, int j, vector<vector<int>>&grid)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            int sz=  q.size();
            while(sz--)
            {
                int di = q.front().first;
                int dj = q.front().second;
                q.pop();
                if(grid[di][dj] == 1)
                return abs(di-i) + abs(dj-j);
                
                int drow[] = {0,1,0,-1};
                int dcol[] = {1,0,-1,0};
                for(int ind = 0; ind < 4; ++ind)
                {
                    int nrow = di + drow[ind];
                    int ncol = dj + dcol[ind];
                    if(nrow>=0 && nrow<grid.size() && ncol >=0 && ncol < grid[0].size())
                    q.push({nrow,ncol});
                }
            }
        }
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int>> ans(n, vector<int>(m,0));
	    for(int i =0 ; i < n; ++i)
	    {
	        for(int j =0 ; j < m; ++j)
	        {
	            ans[i][j] = bfs(i,j,grid);
	        }
	    }
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends