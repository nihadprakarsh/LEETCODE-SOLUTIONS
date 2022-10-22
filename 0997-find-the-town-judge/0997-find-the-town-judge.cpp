class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> edge[n+1];
        vector<int> t[n+1];
        for(auto it : trust){
            edge[it[0]].push_back(it[1]);
            t[it[1]].push_back(it[0]);
        }
        for(int i=1; i <=n ; ++i)
            if(edge[i].size() == 0 && t[i].size() == n-1)
                return i;
        return -1;
    }
};