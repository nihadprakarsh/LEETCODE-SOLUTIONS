class Solution {
public:
    bool check(int mid, vector<int>&weights, int days)
    {
        int c = 0,s=0;
        for(auto &i : weights)
        {
            if(i>mid) return false;
            if(s+i>mid)
            {
                c++;
                s=i;
            }
            else
            s+=i;
        }
        if(s) c++;
        return c<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int wt = accumulate(begin(weights), end(weights),0);
        int low = 0, high = wt, mid, ans;
        while(low<=high)
        {
            mid = (low+high)>>1;
            if(check(mid,weights,days))
            {
                ans = mid;
                high = mid-1;
            }
            else
            low = mid + 1;
        }
        return ans;
    }
};