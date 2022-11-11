//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        int indegree[V] = {0};
        vector<int> adjRev[V];
        for(int i=0; i< V; ++i){
            for(auto node : adj[i]){
            adjRev[node].push_back(i);
            indegree[i]++;
            }
        }
       
       queue<int> q;
       for(int i=0; i < V; ++i){
           if(indegree[i] == 0)
           q.push(i);
       }
       
        vector<int> ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto nodes : adjRev[node]){
            indegree[nodes]--;
            if(indegree[nodes] == 0)
            q.push(nodes);
        }
        }
        
        sort(begin(ans), end(ans));
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends