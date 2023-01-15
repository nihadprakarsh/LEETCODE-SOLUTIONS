//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        map<int,int> m;
        m[0]=-1;
        int ans=0,s=0;
        for(int i=0; i<n;++i)
        {
            s+=a[i];
            if(m.count(s-k))
            ans=max(ans,i-m[s-k]);
            if(m.find(s) == m.end())
            m[s]=i;
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends