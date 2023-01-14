class Solution {
public:
    int ans=0;
    int find(vector<int> adj[], string &s, int ind, int prev)
    {
        int a=0,b=0;
        for(auto &it:adj[ind])
        {
            int c=find(adj,s,it,ind);
            if(s[it] == s[ind]) continue;
            b=max(b,c);
            if(a<b) swap(a,b);
        }
        ans=max(ans,1+a+b);
        return a+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<int> adj[n];
        for(int i=1; i < s.size(); ++i)
        adj[parent[i]].push_back(i);
        find(adj,s,0,-1);
        return ans;
    }
};