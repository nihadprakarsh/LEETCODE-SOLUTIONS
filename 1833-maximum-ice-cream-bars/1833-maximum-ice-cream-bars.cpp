class Solution {
public:
    bool check(int mid, vector<int>&costs, int coins)
    {
        int a=0;
        for(auto &it:costs)
        {
            coins-=it;
            if(coins<0) break;
            a++;
        }
        return a>=mid;
    }
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs),end(costs));
        int low=0,high=INT_MAX,ans=0,mid;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(check(mid,costs,coins))
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};