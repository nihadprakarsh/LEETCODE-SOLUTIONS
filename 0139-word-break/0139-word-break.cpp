class Solution {
public:
    int dp[301];
    bool check(vector<string>&dict,string &res){
        for(auto &it:dict) if(res == it) return true;
        return false;
    }
    bool find(string &s, vector<string>& wordDict,int ind)
    {
        if(ind == s.size()) return true;
        if(dp[ind] != -1) return dp[ind];
        bool flg = false;
        string str = "";
        for(int i=ind;i<s.size();++i)
        {
            str.push_back(s[i]);
            if(check(wordDict,str))
                flg = flg or find(s,wordDict,i+1);
        }
        return dp[ind]=flg;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        return find(s,wordDict,0);
    }
};