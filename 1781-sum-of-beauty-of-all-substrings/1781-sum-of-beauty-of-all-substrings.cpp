class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();++i)
        {
            map<char,int> m;
            for(int j=i;j<s.size();++j)
            {
                m[s[j]]++;
                int a=INT_MAX,b=INT_MIN;
                for(auto &it:m) a=min(a,it.second),b=max(b,it.second);
                ans+=b-a;
            }
        }
        return ans;
    }
};