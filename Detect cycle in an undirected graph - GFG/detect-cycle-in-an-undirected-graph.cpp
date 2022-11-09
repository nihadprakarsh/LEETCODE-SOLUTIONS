//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool cycle(int N, vector<int> adj[],int vis[]){
        queue<pair<int,int>> q;
        vis[N] = 1;
        q.push({N,-1});
        while(!q.empty()){
            auto node = q.front().first;
            auto parent = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else if(parent != it)
                return true;
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i < V; ++i){
            if(!vis[i]){            
                if(cycle(i,adj,vis))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends