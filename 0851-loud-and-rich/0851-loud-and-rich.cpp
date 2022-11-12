class Solution {
public:
    
    int dfs(vector<int>&ans,int i, vector<int>& quiet, vector<int> adj[]){
        if(ans[i] >= 0)
            return ans[i];
        ans[i] = i;
        for(auto node : adj[i]){
            if(quiet[dfs(ans,node,quiet,adj)] < quiet[ans[i]])
            ans[i] = ans[node];
        }
        return ans[i];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> adj[n];
        for(auto it : richer)
        adj[it[1]].push_back(it[0]);
        
        vector<int> ans(n,-1);
        for(int i=0; i < n; ++i){
            dfs(ans,i,quiet,adj);
        }
        return ans;
    }
};