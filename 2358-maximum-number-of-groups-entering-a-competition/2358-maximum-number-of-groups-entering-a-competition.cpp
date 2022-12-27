class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        if(grades.size()==1) return 1;
        long long int low = 0, high = grades.size()-1, mid, ans = 0;
        while(low<=high)
        {
            mid = (low+high)>>1;
            if(mid*(mid+1)/2 <= grades.size())
            {
                ans = mid;
                low = mid + 1;
            }
            else
            high = mid - 1;
        }
        return ans;
    }
};