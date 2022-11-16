//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	typedef pair<int,int> pt;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       priority_queue<pt,vector<pt>,greater<pt>> q;
       vector<int> vis(V,0);
       q.push({0,0});
       int sum = 0;
       while(!q.empty())
       {
           auto it = q.top();
           q.pop();
           int node = it.second;
           int wt = it.first;
           
           if(vis[node] == 1) continue;
           vis[node] = 1;
           sum += wt;
           for(auto nodes : adj[node]){
               int adjNode = nodes[0];
               int wtt = nodes[1];
               if(!vis[adjNode]){
                   q.push({wtt,adjNode});
               }
           }
       }
       return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends