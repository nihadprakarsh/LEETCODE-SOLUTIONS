class Solution {
public:
    int binarySearch(vector<vector<int>>&events, int i)
    {
        int low=i+1,high=events.size()-1,ans=events.size(),mid;
        while(low<=high){
            mid=(low+high)>>1;
            if(events[mid][0]>events[i][1]){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
    int find(vector<vector<int>>& events,int ind,int k,vector<vector<int>> &dp)
    {
        if(k==0) return 0;
        if(ind == events.size()) return 0;
        if(dp[ind][k]!=-1) return dp[ind][k];
        int a= 0 ;
        int getind = binarySearch(events,ind);
        // cout<<getind<<" "<<events[ind][2] << endl;
        a=max(a,events[ind][2]+find(events,getind,k-1,dp));
        a=max(a,find(events,ind+1,k,dp));
        return dp[ind][k]=a;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        // memset(dp,-1,sizeof(dp));
        vector<vector<int>> dp(events.size()+1,vector<int>(k+1,-1));
        sort(begin(events),end(events));
        return find(events,0,k,dp);
    }
};