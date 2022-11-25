class DSU{
	public:
    vector<int> rank, parent;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> v;
        int n = edges.size();
        DSU dsu(n);
        for(auto it : edges)
        {
            if(dsu.findParent(it[0]) == dsu.findParent(it[1]))
            v.push_back(it);
            else
            dsu.Union(it[0], it[1]);
        }
        return v[v.size()-1];
    }
};




















