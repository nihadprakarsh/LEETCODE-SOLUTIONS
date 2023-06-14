//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
// 	int dp[1001][1001];
    int find(int arr[],int n,int i,int prev,vector<vector<int>>&dp)
    {
        if(i == n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int a=0;
        if(prev==-1 || arr[i]>arr[prev])
        a=arr[i]+find(arr,n,i+1,i,dp);
        a=max(a,find(arr,n,i+1,prev,dp));
        return dp[i][prev+1]=a;
    }
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	   // memset(dp,-1,sizeof(dp));
	   vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	    return find(arr,n,0,-1,dp);
	    
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends