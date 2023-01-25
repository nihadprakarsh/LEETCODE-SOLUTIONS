class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& f) {
        vector<int> ans;
        unordered_map<string,unordered_set<int>> m;
        for(int i=0;i<f.size();++i)
        {
            for(auto &str:f[i])
            m[str].insert(i);
        }
        for(int i=0;i<f.size();++i)
        {
            int c=0,n=f[i].size();
            for(int j=0;j<f.size();++j)
            {
                if(i!=j)
                {
                    int s=0;
                    for(auto &str:f[i])
                    if(m[str].count(j)) s++;
                    if(s==n)
                    c=1;
                }
            }
            if(c==0) ans.push_back(i);
        }
        return ans;
    }
};