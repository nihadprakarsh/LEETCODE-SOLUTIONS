class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0; i < n; ++i){
            for(int j =0; j < m; ++j){
                if(board[i][j] == 'O' && (i==0 || i == n-1 || j == 0 || j == m-1)){
                    vis[i][j]  = 1;
                    q.push({i,j});
                }
            }
        }
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i =0; i < 4; ++i)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && board[nrow][ncol] == 'O' && !vis[nrow][ncol])
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        for(int i =0; i < n; ++i)
        {
            for(int j =0; j < m; ++j)
            {
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};