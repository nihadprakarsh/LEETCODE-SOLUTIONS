class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int low=0,high=m.size()*m[0].size()-1;
        while(low<=high)
        {
            int mid = (low+high)>>1;
            int row = mid/m[0].size();
            int col = mid%m[0].size();
            if(m[row][col]==target)
                return true;
            else if(m[row][col] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }
};