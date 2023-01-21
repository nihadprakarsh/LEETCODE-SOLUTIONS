class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> m1(26,0),m2(26,0);
        for(auto &ch:word1)
        m1[ch-'a']++;
        for(auto &ch:word2)
        m2[ch-'a']++;
        for(int i=0;i<26;++i)
        {
            for(int j=0;j<26;++j)
            {
                    if(m1[i] && m2[j])
                    {
                        m1[i]--; m2[i]++;
                    m1[j]++; m2[j]--;
                    int u1=0,u2=0;
                    for(int z=0;z<26;++z)
                    {
                        if(m1[z]>0) u1++;
                        if(m2[z]>0) u2++;
                    }
                    if(u1==u2)
                    return true;
                    m1[i]++; m2[i]--;
                    m1[j]--; m2[j]++;
                }
            }
        }
        return false;
    }
};