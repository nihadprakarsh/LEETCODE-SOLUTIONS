class Solution {
public:
    int dp[501][501];
    int find(int ind1, int ind2, string &word1, string &word2)
    {
        if(ind1 == word1.size()) return word2.size()-(ind2+1);
        if(ind2 == word2.size()) return word1.size()-(ind1+1);
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(word1[ind1] == word2[ind2])
        return find(ind1+1,ind2+1,word1,word2);
        else
        return dp[ind1][ind2] = 1 + min(find(ind1+1,ind2,word1,word2),min(find(ind1,ind2+1,word1,word2),find(ind1+1,ind2+1,word1,word2)));
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return 1 + find(0,0,word1,word2);
    }
};