class Solution {
public:
    typedef unsigned long long int ll;
    bool find(ll t,ll totalTrips,vector<int>&time)
    {
        ll c=0;
        for(auto &it:time)
        c+=t/it;
        return c>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll low=0,high=1e15,ans,mid;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(find(mid,totalTrips,time))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};