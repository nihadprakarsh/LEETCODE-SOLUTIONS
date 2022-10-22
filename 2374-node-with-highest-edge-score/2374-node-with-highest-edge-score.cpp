class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long int> indegree(n,0);
        for(int i=0; i < n; ++i)
            indegree[edges[i]]+=i;
        long long int maxi = 0;
        for(int i =0; i < n; ++i)
            maxi = max(maxi,indegree[i]);
        for(int i= 0; i < n; ++i)
            if(indegree[i] == maxi)
                return i;
        return -1;
    }
};