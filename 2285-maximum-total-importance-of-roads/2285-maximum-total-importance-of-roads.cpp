class Solution {
public:
    static bool comp(pair<int,int>&a, pair<int,int> &b){
        return a.second > b.second;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for(auto it : roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<pair<int,int>> v;
        for(int i=0; i < n; ++i)
        {
            int count = adj[i].size();
            v.push_back({i,count});
        }
        
        sort(begin(v), end(v), comp);
        map<int,int> m;
        int sc = n;
        for(auto it : v)
        m[it.first] = sc--;
        
        vector<int> newadj[n];
        for(auto it : roads)
            newadj[it[0]].push_back(it[1]);
        
        long long ans = 0;
        for(int i=0; i< n; ++i)
        {
            for(auto node : newadj[i])
                ans+=m[node]+m[i];
        }
        
        return ans;
    }
};