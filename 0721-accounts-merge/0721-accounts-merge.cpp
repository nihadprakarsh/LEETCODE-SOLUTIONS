class DSU{
	vector<int> rank, parent;
	public:
	DSU(int n){
		rank.resize(n+1,0);
		parent.resize(n+1);
		for(int i=0; i <= n; ++i)
		parent[i] = i;
	}

	int findParent(int node)
	{
		if(node==parent[node])
		return node;
		return parent[node] = findParent(parent[node]);
	}

	void Union(int u, int v)
	{
		int ulp_u = findParent(u);
		int ulp_v = findParent(v);
		if(ulp_u == ulp_v) return;
		if(rank[ulp_u] < rank[ulp_v])
		parent[ulp_u] = ulp_v;
		else if(rank[ulp_v] < rank[ulp_u])
		parent[ulp_v] = ulp_u;
		else
		{
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        map<string,int> m;
        for(int i =0; i < n; ++i)
        {
            int size = accounts[i].size();
            for(int j = 1; j < size; ++j)
            {
                if(m.find(accounts[i][j]) == m.end())
                m[accounts[i][j]] = i;
                else
                dsu.Union(i, m[accounts[i][j]]);
            }
        }
        map<int,vector<string>> m1;
        for(auto it : m)
        {
            string str = it.first;
            int parent = it.second;
            int uParent = dsu.findParent(parent);
            if(parent == uParent) 
            m1[parent].push_back(str);
            else
            m1[uParent].push_back(str);
        }
        vector<vector<string>> ans;
        for(int i=0; i < n ; ++i)
        {
            if(m1.count(i))
            {
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto str : m1[i])
                temp.push_back(str);
                sort(begin(temp)+1, end(temp));
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};












