class Solution {
public:
    void getVal(map<string,vector<pair<string,double>>> &m, string str, double &ans, string tar,set<string>&st,double temp)
    {
        if(st.count(str)) return;
        else
        {
            st.insert(str);
            if(str == tar)
            {
                ans = temp;
                return;
            }
            
            else
            {
                for(auto nodes : m[str])
                {
                    getVal(m,nodes.first,ans,tar,st,temp*nodes.second);
                }
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        set<string> unique;
        for(auto it : equations)
        {
            unique.insert(it[1]);
            unique.insert(it[0]);
        }
        map<string,vector<pair<string,double>>> m;
        for(int i=0; i < equations.size(); ++i){
            m[equations[i][1]].push_back({equations[i][0],1/values[i]});
            m[equations[i][0]].push_back({equations[i][1],values[i]});   
        }
        vector<double> ans;
        for(auto it : queries)
        {
            double val = -1;
            set<string> st;
            if(it[0] == it[1])
            {
                if(unique.count(it[0]))
                val = 1;
            }
            else
            getVal(m,it[0],val,it[1],st,1.0);
            ans.push_back(val);
        }
        return ans;
    }
};