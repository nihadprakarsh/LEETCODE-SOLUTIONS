class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int ans = 0;
        while(!q.empty())
        {
            int sz= q.size();
            while(sz--)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                int drow[]={0,1,0,-1};
                int dcol[]={1,0,-1,0};
                for(int i=0; i < 4; ++i)
                {
                    int nrow =r  + drow[i];
                    int ncol = c + dcol[i];
                    if(nrow >=0 && nrow < maze.size() && ncol >=0 && ncol < maze[0].size() && maze[nrow][ncol] != '+')
                    {
                        q.push({nrow,ncol});
                        maze[nrow][ncol] = '+';
                    }
                    else if((r==0||c==0||r==maze.size()-1||c==maze[0].size()-1) && (r!=entrance[0] || c!=entrance[1]))
                        return ans;
                }
                
            }
            ans++;
        }
        return -1;
    }
};