class Solution {
public:
    bool check(int mid, int h, vector <int> piles)
    {
        int count = 0;
        for(auto &it : piles)
        {
            if(it < mid)
                count++;
            else if(it >= mid && it % mid == 0)
                count+=it/mid;
            else
                count+=it/mid + 1;
        }
        return count <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MAX;
        int mid, ans = 0;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(check(mid, h, piles))
            {
                ans = mid;
                high = mid - 1;
            }
            else 
                low = mid + 1;
        }
        return ans;
    }
};