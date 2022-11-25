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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow, maxCol;
        set<int> st;
        for(auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DSU dsu(maxRow + maxCol + 1);
        for(auto it : stones)
        {
            int row = it[0];
            int col = it[1] + maxRow + 1;
            dsu.Union(row, col);
            
           st.insert(row); st.insert(col);
        }
        
        int ans = 0;
        for(auto it : st)
        {
            if(dsu.findParent(it) == it)
            ans++;
        }
        return stones.size()-ans;
    }
};