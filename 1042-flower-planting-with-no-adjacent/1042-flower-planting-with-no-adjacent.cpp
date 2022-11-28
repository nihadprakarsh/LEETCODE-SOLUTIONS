class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n];
        for(auto it:  paths)
        {
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        vector<int> usedColor(n,-1);
        for(int i =0; i < n; ++i)
        {
            int color[4] = {0,0,0,0};
            for(auto nodes : adj[i])
            {
                if(usedColor[nodes] != -1)
                color[usedColor[nodes]-1] = 1;
            }
            for(int j=0; j < 4; ++j)
            {
                if(color[j] == 0)
                {
                    usedColor[i] = j+1;
                    break;
                }
            }
        }
        return usedColor;
    }
};