class Solution {
public:
    
    // int res = 0;
    vector<int> visited;
    int dfs(int curr,vector<int> adj[]){
        
        visited[curr] = true;
        int res = 0;
        
        for(auto x:adj[curr]){
            res = max(res,dfs(x,adj));
        }
        return res + 1;
    }
    
    int maximumInvitations(vector<int>& fav){
        
        int n = fav.size();
        vector<int> adj[n];
        visited.resize(n,false);
        for(int i = 0 ; i < n;i++){
            if(fav[fav[i]] != i) adj[fav[i]].push_back(i); 
        }
        
        int res = 0;
        
        for(int i = 0; i < n;i++){
            if(fav[fav[i]] == i) res += dfs(i,adj);
        }
        
        for(int i = 0;i < n;i++){
            int cnt = 0, j = i;
            for(;visited[j] == false;j = fav[j]){
                visited[j]  = true;
                cnt++;
            }
            for(int k = i;k != j;k = fav[k]) cnt--;
            res = max(res,cnt);
        }
        
        return res;
    }
};