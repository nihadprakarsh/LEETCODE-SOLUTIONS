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
    
    bool checkParent(int n, set<int>&validnodes)
    {
        set<int> st;
        for(int i=0; i < n ;++i)
        {
            if(validnodes.count(i))
            st.insert(parent[i]);
        }
        return st.size() <= 2;
    }
};
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DSU dsu(n);
        int indegree[n];
        memset(indegree, 0, sizeof(indegree));
        for(int i=0; i < n; ++i)
        {
            if(leftChild[i] != -1 && ++indegree[leftChild[i]] > 1)
                return false;
            if(rightChild[i] != -1 && ++indegree[rightChild[i]] > 1)
                return false;
        }
        
        int root = -1;
        for(int i = 0 ; i < n; ++i)
        {
            if(indegree[i] == 0)
            root++;
        }
        if(root == -1 || root > 0) return false;
        
       for(int i=0; i < n ;++i)
       {
           int lc = leftChild[i];
           int rc = rightChild[i];
           if(lc != -1)
            dsu.UnionbyRank(i, lc);
           if(rc != -1)
            dsu.UnionbyRank(i, rc);
       }
    
        int c = 0;
        for(int i =0 ; i < n ; ++i)
        {
            if(dsu.parent[i] == i)
            c++;
        }
        return c == 1;
    }
};

























