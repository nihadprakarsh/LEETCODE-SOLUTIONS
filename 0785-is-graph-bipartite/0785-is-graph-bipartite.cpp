class Solution {
public:
    bool check(int n, int V, vector<int> adj[],int color[]){
        queue<int> q;
	    q.push(n);
	    color[n] = 0;
	    while(!q.empty()){
	        auto node = q.front();
	        q.pop();
	        for(auto it : adj[node]){
	            if(color[it] == -1){
	                color[it] = !color[node];
	                q.push(it);
	            }
	            else if(color[it] == color[node])
	            return false;
	        }
	    }
	    return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        for(int i=0; i < graph.size(); ++i){
            for(auto node : graph[i])
            adj[i].push_back(node);
        }
        int color[V];
	    memset(color,-1,sizeof(color));
	    for(int i=0 ;i < V; ++i){
	        if(color[i] == -1){
	            if(check(i,V,adj,color) == false)
	            return false;
	        }
	    }
	    return true;
    }
};