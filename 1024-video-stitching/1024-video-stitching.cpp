class Solution {
public:
    int dp[101][102];
    int find(int ind,vector<vector<int>>&clips,int time,int prev)
    {
        if(prev==time) return 0;
        if(ind==clips.size())
        {
            if(prev == time)
                return 0;
            return 1e7;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int ans = 1e7;
        if(prev==-1 || (clips[ind][0]<=prev && prev<=clips[ind][1]))
        {
            int st=prev==-1?clips[ind][0]:prev;
            if(prev==-1 && clips[ind][0] != 0) return 1e7;
            if(prev != -1) st = min(prev,clips[ind][0]);
            for(int i=st;i<=clips[ind][1];++i)
                ans=min(ans,1+find(ind+1,clips,time,i));
        }
        ans=min(ans,find(ind+1,clips,time,prev));
        return dp[ind][prev+1]=ans;
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        memset(dp,-1,sizeof(dp));
        sort(begin(clips),end(clips));
        return find(0,clips,time,-1)>=1e7?-1:find(0,clips,time,-1);
    }
};