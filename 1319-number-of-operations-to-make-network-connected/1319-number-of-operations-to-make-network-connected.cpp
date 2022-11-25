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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int count = 0;
        for(auto it : connections)
        {
            if(dsu.findParent(it[0]) == dsu.findParent(it[1]))
            count++;
            else
            dsu.Union(it[0], it[1]);
        }
        
        int ans =0 ;
        for(int i=0; i < n; ++i)
        {
            if(dsu.parent[i] == i)
                ans++;
        }
        ans--;
        if(count >= ans)
        return ans;
        return -1;
    }
};