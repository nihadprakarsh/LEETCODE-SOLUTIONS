class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> side[edges.size()+2];
        for(auto it: edges)
        {
            side[it[0]].push_back(it[1]);
            side[it[1]].push_back(it[0]);
        }
        int n = edges.size()+1;
        for(int i = 1; i <=n ; ++i)
            if(side[i].size() == n-1)
                return i;
        return -1;
    }
};