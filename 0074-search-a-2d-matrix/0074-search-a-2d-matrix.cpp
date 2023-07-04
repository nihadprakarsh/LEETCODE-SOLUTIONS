class Solution {
public:
    bool find(vector<vector<int>>& matrix, int target)
    {
        int i =0;
        while(i+1<matrix.size() and matrix[i+1][0]<=target) i++;
        int low=0,high=matrix[0].size()-1;
        while(low<=high)
        {
            int mid = (low+high)>>1;
            if(matrix[i][mid] == target) return true;
            else if(matrix[i][mid] < target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return find(matrix,target);
    }
};