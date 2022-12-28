class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=0,c=matrix[0].size()-1;
        while(r < matrix.size() && c >=0)
        {
            if(matrix[r][c] == target) return true;
            if(target>matrix[r][c]) r+=1;
            else c-=1;
        }
        return false;
    }
};