class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(),0));
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>,int>> q;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i < n; ++i){
            for(int j =0; j < m; ++j){
                if(mat[i][j] == 0)
                q.push({{i,j},0});
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            vis[r][c] = 1;
            ans[r][c] = dis;
            for(int i =0 ; i <4; ++i){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr >=0 && nr < n && nc >=0 && nc < m && !vis[nr][nc] && mat[nr][nc] != 0){
                vis[nr][nc] = 1;
                q.push({{nr,nc},dis+1});
                }
            }
        }
        return ans;
    }
};