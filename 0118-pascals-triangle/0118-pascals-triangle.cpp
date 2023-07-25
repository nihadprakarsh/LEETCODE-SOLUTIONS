class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v;
        v.push_back({1});
        for(int i=1;i<n;++i)
        {
            vector<int> temp(i+1);
            for(int j=0;j<=i;++j)
            {
                int a=0;
                if(j<v[i-1].size())
                    a=v[i-1][j];
                if(j-1<v[i-1].size() && j-1>=0)
                    a+=v[i-1][j-1];
                temp[j]=a;
            }
            v.push_back(temp);
        }
        return v;
    }
    
};