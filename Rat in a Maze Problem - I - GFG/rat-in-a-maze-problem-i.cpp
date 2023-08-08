//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void find(vector<vector<int>>&m,int n,int i,int j,string str,vector<vector<int>>&vis)
    {
        if(i<0||j<0||i==m.size()||j==m[0].size()||m[i][j]==0||vis[i][j]==1) return;
        
        if(i==n-1 && j==n-1)
        {
            ans.push_back(str);
            return;
        }
        
        vis[i][j]=1;
        str+="D";
        find(m,n,i+1,j,str,vis);
        str.pop_back();
        str+="L";
        find(m,n,i,j-1,str,vis);
        str.pop_back();
        str+="R";
        find(m,n,i,j+1,str,vis);
        str.pop_back();
        str+="U";
        find(m,n,i-1,j,str,vis);
        str.pop_back();
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis(m.size()+1,vector<int>(m[0].size()+1,0));
        find(m,n,0,0,"",vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends