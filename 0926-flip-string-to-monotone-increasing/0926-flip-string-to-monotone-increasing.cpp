class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> one(s.size(),0),zero(s.size(),0);
        int o=0,z=0;
        for(int i=0;i<s.size();++i)
        {
            one[i]=o;
            if(s[i]=='1')
            o++;
        }
        for(int i=s.size()-1;i>=0;--i)
        {
            zero[i]=z;
            if(s[i]=='0')
            z++;
        }
        int ans=INT_MAX;
        for(int i=0;i<s.size();++i)
            ans=min(ans,zero[i]+one[i]);
        return ans;
    }
};