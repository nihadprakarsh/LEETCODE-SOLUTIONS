class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> indegree[n],outdegree[n];
        vector<int> vis(n,0);
        for(auto it : connections){
            indegree[it[1]].push_back(it[0]);
            outdegree[it[0]].push_back(it[1]);
        }
        int ans =0 ;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            vis[node] = 1;
            for(auto it : outdegree[node]){
                if(!vis[it]){
                    ans++;
                    q.push(it);
                }
            }
            
            for(auto it : indegree[node]){
                if(!vis[it])
                    q.push(it);
            }
        }
        return ans;
    }
};