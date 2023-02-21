class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        int n = s.size();
        vector<int> ans;
        vector<int> pre(n,0), suff(n,0);
        int c=0;
        for(int i=0;i<s.size();++i)
        {
            if(i==0 || s[i]<=s[i-1])
            c++;
            else
            c=0;
            pre[i]=c;
        }
        c=0;
        for(int i=n-1;i>=0;--i)
        {
            if(i==n-1 || s[i]<=s[i+1])
            c++;
            else
            c=0;
            suff[i]=c;
        }
        for(int i=0;i<s.size();++i)
        {
            if(i>=time && s.size()-i-1>=time)
            {
                if(pre[i]>=time && suff[i]>=time)
                ans.push_back(i);
            }
        }
        return ans;
    }
};