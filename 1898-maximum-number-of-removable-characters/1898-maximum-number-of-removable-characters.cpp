class Solution {
public:
    bool check(int mid,string &s, string &p, vector<int>&r)
    {
        string temp = "";
        vector<int> vis(s.size(),0);
        for(int i=0; i < mid;++i)
        vis[r[i]]=1;
        for(int i=0; i < s.size(); ++i)
        if(!vis[i]) temp.push_back(s[i]);
        int i=0;
        for(auto &it:temp)
        {
            if(it==p[i])
            i++;
        }
        return i>=p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& r) {
        int low=0,high=r.size(),mid,ans;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(check(mid,s,p,r))
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};