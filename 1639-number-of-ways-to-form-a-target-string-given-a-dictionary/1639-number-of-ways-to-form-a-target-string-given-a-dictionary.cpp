class Solution {
public:
    long long int dp[1001][1001];
    int mod = 1e9+7;
    long long int find(string &target, vector<vector<int>>&v, int i, int j)
    {
        if(j == target.size()) return 1;
        if(i == v.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        ans+=find(target,v,i+1,j)%mod;
        if(v[i][target[j]-'a'])
        ans+=(find(target,v,i+1,j+1)*v[i][target[j]-'a']*1LL)%mod;
        return dp[i][j] = ans;
    } 
    int numWays(vector<string>& words, string target) {
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> v(1001,vector<int>(27,0));
        for(auto &word : words)
        {
            for(int i =0 ; i < word.size(); ++i)
            v[i][word[i]-'a']++;
        }
        return find(target,v,0,0)%mod;
    }
};