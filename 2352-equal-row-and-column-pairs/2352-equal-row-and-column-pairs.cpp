class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> m1;
        vector<vector<int>> v;
        for(int i=0; i<grid.size(); ++i){
            vector<int> fv,fv1;
            for(int j= 0; j < grid[0].size(); ++j){
                fv.push_back(grid[i][j]);
                fv1.push_back(grid[j][i]);
            }
            v.push_back(fv);
            m1[fv1]++;
        }
        int ans = 0;
        for(auto it : v){
            ans+=m1[it];
        }
        return ans;
    }
};
