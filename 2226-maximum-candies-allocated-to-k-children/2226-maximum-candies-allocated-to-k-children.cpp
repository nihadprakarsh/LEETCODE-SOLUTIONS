class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1,high=INT_MAX,mid,ans=0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            long long cnt=0;
            for (int i = 0; i < candies.size(); ++i)
            cnt += candies[i] / mid;
            if(cnt>=k)
            {
                low=mid+1;
                ans=mid;
            }
            
            else
            high=mid-1;
        }
        return ans;
    }
};