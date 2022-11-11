//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> v;
	    for(int i=0; i < nums.size(); ++i){
	        v.push_back({nums[i],i});
	    }
	    
	    sort(begin(v), end(v));
	    
	    int count = 0;
	    for(int i=0; i< nums.size(); ++i){
	        if(v[i].second == i)
	        continue;
	        else
	        {
	            int ind = v[i].second;
	            pair<int,int> temp = v[ind];
	            v[ind] = v[i];
	            v[i] = temp;
	            i--;
	            count++;
	        }
	    }
	    return count++;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends