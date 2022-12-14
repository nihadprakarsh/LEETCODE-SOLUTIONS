class Solution {
public:
    int ans = 0;
    int dp[1001][1001];
    int find(vector<pair<int,int>>&v, int ind, int prev)
    {
        if(ind == v.size()) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int a = 0, b =  0;
        if(prev==-1 || v[ind].second >= v[prev].second)
        a = v[ind].second + find(v,ind+1,ind);
        b = find(v,ind+1,prev);
        return dp[ind][prev+1] = max(a,b);
        
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        memset(dp, -1, sizeof(dp));
        vector<pair<int,int>> v;
        for(int i =0 ; i < ages.size(); ++i)
        v.push_back({ages[i], scores[i]});
        sort(begin(v), end(v));
        return find(v,0,-1);
    }
};