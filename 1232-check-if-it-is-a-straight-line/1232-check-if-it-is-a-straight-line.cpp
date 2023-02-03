class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        set<double> st;
        for(int i=0;i<c.size();++i)
        {
            for(int j=0;j<c.size();++j)
            {
                if(i!=j)
                {
                    double s=(double)abs(c[i][0]-c[j][0])/(double)abs(c[i][1]-c[j][1]);
                    st.insert(s);
                }
            }
        }
        return st.size()==1;
    }
};