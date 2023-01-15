class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> matp(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            int s=0;
            for(int j=0;j<m;++j)
            {
                s+=mat[i][j];
                matp[i][j]=s;
            }
        }
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int s=0;
                for(int z=max(0,i-k);z<=min(n-1,i+k);++z)
                {
                    int l=max(0,j-k);
                    int r=min(m-1,j+k);
                    s+=matp[z][r]-matp[z][l]+mat[z][l];
                }
                ans[i][j]=s;
            }
        }
        return ans;
    }
};