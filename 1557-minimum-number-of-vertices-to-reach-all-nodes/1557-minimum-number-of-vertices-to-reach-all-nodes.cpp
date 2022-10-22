class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n], indegree[n];
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]].push_back(it[0]);
        }
        vector<int> ans;
        for(int i =0; i< n; ++i)
            if(indegree[i].size()==0)
                ans.push_back(i);
        return ans;
    }
};