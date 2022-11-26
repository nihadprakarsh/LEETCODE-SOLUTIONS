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
private:
    int maxi = 0;
    bool isValid(int nrow, int ncol, int n)
    {
        return nrow>=0 && nrow < n && ncol >=0 && ncol < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n*n);
        for(int i=0; i < n; ++i)
        {
            for(int j=0; j < n; ++j)
            {
                if(grid[i][j] == 0)
                continue;
                int drow[] = {0,1,0,-1};
                int dcol[] = {1,0,-1,0};
                for(int ind = 0; ind < 4; ++ind)
                {
                    int nrow = i + drow[ind];
                    int ncol = j + dcol[ind];
                    if(isValid(nrow,ncol,n) && grid[nrow][ncol] == 1)
                    {
                        int nodeNum = i * n + j;
                        int adjNode = nrow * n + ncol;
                        dsu.UnionbySize(nodeNum, adjNode);
                    }
                }
            }
        }
        
        for(int i=0; i < n ;++i)
        {
            for(int j =0; j < n; ++j)
            {
                if(grid[i][j] == 0)
                {
                    set<int> st;
                    int drow[] = {0,1,0,-1};
                    int dcol[] = {1,0,-1,0};
                    int size =0 ;
                    for(int ind = 0; ind < 4; ++ind)
                    {
                        int nrow = i + drow[ind];
                        int ncol = j + dcol[ind];
                        if(isValid(nrow,ncol,n) && grid[nrow][ncol] == 1)
                        {
                            int adjNode = nrow * n + ncol;
                            st.insert(dsu.findParent(adjNode));
                        }
                    }
                    
                    for(auto it : st)
                    size += dsu.size[it];
                    maxi = max(maxi,size+1);
                }
            }
        }
        for(int i =0 ; i < n*n; ++i)
        maxi = max(maxi, dsu.size[i]);
        return maxi;
    }
};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    