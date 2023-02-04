//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int dp[101][101][201];
    int find(string &a, string &b, string &c, int i, int j, int k)
    {
        if(k==c.size())
        {
            if(i==a.size() && j==b.size())
            return true;
            else
            return false;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        bool flag=false;
        if(i<a.size() && a[i]==c[k])
        flag|=find(a,b,c,i+1,j,k+1);
        if(j<b.size() && b[j]==c[k])
        flag|=find(a,b,c,i,j+1,k+1);
        return dp[i][j][k]=flag;
    }
    bool isInterleave(string A, string B, string C) 
    {
        memset(dp,-1,sizeof(dp));
        return find(A,B,C,0,0,0);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends