class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        vector<double> v;
        for(int i=0;i<c.size();++i)
        {
            for(int j=0;j<c.size();++j)
            {
                if(i!=j)
                {
                    double s=(double)abs(c[i][0]-c[j][0])/(double)abs(c[i][1]-c[j][1]);
                    v.push_back(s);
                }
            }
        }
        for(int i=1;i<v.size();++i)
        if(v[i]!=v[i-1]) return false;
        return true;
    }
};