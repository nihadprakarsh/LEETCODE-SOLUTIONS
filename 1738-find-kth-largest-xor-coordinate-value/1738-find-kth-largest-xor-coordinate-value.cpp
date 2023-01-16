class Solution {
public:
    int kthLargestValue(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            int x=0;
            for(int j=0;j<m;++j)
            {
                x^=mat[i][j];
                v[i][j]=x;
            }
        }
        int x=0;
        vector<int> fv;
        for(int i=0;i<m;++i)
        {
            x=0;
            for(int j=0;j<n;++j)
            {
                x^=v[j][i];
                v[j][i]=x;
                fv.push_back(v[j][i]);
            }
        }
        sort(begin(fv),end(fv));
        while(--k)
        fv.pop_back();
        return fv.back();
    }
};