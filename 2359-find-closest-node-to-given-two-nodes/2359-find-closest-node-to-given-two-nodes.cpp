class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>&edges,int step)
    {
        vis[node]=step;
        if(edges[node] != -1 && vis[edges[node]]==-1)
        dfs(edges[node],vis,edges,step+1);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n =edges.size();
        vector<int> vis1(n,-1),vis2(n,-1);
        dfs(node1,vis1,edges,0);
        dfs(node2,vis2,edges,0);
        int ans=INT_MAX,t;
        for(int i=0;i<n;++i)
        {
            int a=vis1[i],b=vis2[i];
            if(min(a,b)>=0 && max(a,b)<ans)
            {
                ans=max(a,b);
                t=i;
            }
        }
        if(ans==INT_MAX) return -1;
        return t;
    }
};