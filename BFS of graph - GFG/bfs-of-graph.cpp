//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> ans;
    void bfs(int i, vector<int>adj[],vector<int>&vis){
        queue<pair<int,int>> q;
        q.push({i,-1});
        vis[i] = 1;
        while(!q.empty()){
            auto front = q.front().first;
            auto parent = q.front().second;
            q.pop();
            
            ans.push_back(front);
            for(auto node : adj[front]){
                if(node != parent && !vis[node]){
                    q.push({node,parent});
                    vis[node] = 1;
                }
                
            }
        }
        
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        bfs(0,adj,vis);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends