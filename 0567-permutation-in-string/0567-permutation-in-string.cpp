class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> m1,m2;
        for(auto &it:s1) m1[it]++;
        int i=0,j=0,ans=0;
        while(j<s2.size())
        {
            m2[s2[j]]++;
            while(m2[s2[j]]>m1[s2[j]])
            {
                m2[s2[i]]--;
                if(m2[s2[i]]==0)
                m2.erase(s2[i]);
                i++;
            }
            if(m1==m2)
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};