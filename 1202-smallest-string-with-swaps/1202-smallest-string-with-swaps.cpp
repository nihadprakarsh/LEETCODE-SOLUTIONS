class DSU{
	public:
	vector<int> rank, parent, size;
	DSU(int n){
		rank.resize(n+1,0);
		parent.resize(n+1);
		size.resize(n+1);
		for(int i=0; i <= n; ++i){
		parent[i] = i;
		size[i] = 1;
	   }
	}

	int findParent(int node)
	{
		if(node==parent[node])
		return node;
		return parent[node] = findParent(parent[node]);
	}

	void UnionbyRank(int u, int v)
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
	
	void UnionbySize(int u, int v)
	{
		int ulp_u = findParent(u);
		int ulp_v = findParent(v);
		if(ulp_u == ulp_v) return;
		if(size[ulp_u] < size[ulp_v])
		{
			size[ulp_v] += size[ulp_u];
			parent[ulp_u] = ulp_v;
		}
		else
		{
			size[ulp_u] += size[ulp_v];
			parent[ulp_v] = ulp_u;
		}
	}
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> m;
        int n = s.size();
        DSU dsu(n);
        // string str = "";
        for(auto it : pairs)
        {
            int node1 = it[0];
            int node2 = it[1];
            dsu.UnionbySize(node1,node2);
        }
        
       // unordered_map<int,vector<int> > mp;
        for(int i=0; i< n ;i++){
            m[dsu.findParent(i)].push_back(i);
        }
        
        for(auto it : m)
        {
            string st = "";
            for(auto ind : it.second)
            st.push_back(s[ind]);
            
            sort(begin(st), end(st));
            
            for(auto ind : it.second)
            {
                s[ind] = st.front();
                st.erase(0,1);
            }
        }
        return s;
    }
};
















