class Solution {
public:
    int dp[100001];
    int getInd(int val,vector<vector<int>>&intervals)
    {
        int low=0,high=intervals.size()-1,mid,ans=intervals.size();
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(intervals[mid][0]>=val)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    int find(vector<vector<int>>&intervals, int ind)
    {
        if(ind>=intervals.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        if(ind+1<intervals.size() && intervals[ind+1][0]<intervals[ind][1])
        {
            int b=1+find(intervals,ind+1);
            int i=getInd(intervals[ind][1],intervals),c=i-ind-1;
            int a=c+find(intervals,i);
            return dp[ind]=min(a,b);
        }
        else{
        int c=find(intervals,ind+1);
        return dp[ind]=c;
        }
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        memset(dp,-1,sizeof(dp));
        // for(auto &it:intervals) cout << it[0] << " " << it[1] << "  ";
        return find(intervals,0);
    }
};