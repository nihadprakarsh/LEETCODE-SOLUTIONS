class Solution {
public:
    int ans =INT_MAX;
    void find(vector<int>&cookies,vector<int>&vis,int k,int ind)
    {
        if(ind>=cookies.size())
        {
            int mx=*max_element(begin(vis),end(vis));
            ans=min(ans,mx);
            return;
        }
        
        for(int i=0;i<k;++i)
        {
            vis[i]+=cookies[ind];
            find(cookies,vis,k,ind+1);
            vis[i]-=cookies[ind];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> vis(k,0);
        find(cookies,vis,k,0);
        return ans;
    }
};