class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& p) {
        vector<int> adj[N];
        int indegree[N];
        memset(indegree, 0, sizeof(indegree));
        for(auto it : p){
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i =0; i < N; ++i){
            for(auto node : adj[i]){
                indegree[node]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i < N; ++i){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto nodes : adj[node]){
                indegree[nodes]--;
                if(indegree[nodes] == 0)
                    q.push(nodes);
            }
        }
        
        if(topo.size() == N)
            return topo;
        return {};
    }
};