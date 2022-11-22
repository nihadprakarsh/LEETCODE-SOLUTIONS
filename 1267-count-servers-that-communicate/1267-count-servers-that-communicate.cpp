class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n =grid.size(), m =grid[0].size();
        int row[n], column[m];
        memset(row, 0, sizeof(row));
        memset(column, 0, sizeof(column));
        int ans = 0;
        for(int i=0; i < n; ++i)
        {
            for(int j=0; j < m; ++j)
            {
                if(grid[i][j] == 1)
                {
                    cout << i << " " << j << " ";
                    row[i]++;
                    column[j]++;   
                }
            }
        }
        
//         for(int i=0; i < n; ++i)
//         cout << row[i] << " ";
//         cout << endl;
        
//         for(int j=0 ; j < m; ++j)
//         cout << column[j] << " ";
        
        for(int i=0; i < n; ++i)
        {
            for(int j=0; j < m; ++j)
            {
                if(grid[i][j] == 1 && (row[i] > 1 || column[j] > 1))
                ans++;
            }
        }
        return ans;
    }
};