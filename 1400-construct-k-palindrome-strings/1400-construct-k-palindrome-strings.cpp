class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        map<int,int> m;
        for(int i=0;i<s.size();++i)
        m[s[i]]++;
        int c=0;
        for(auto &it:m) c+=it.second%2;
        if(c>k) return false;
        return true;
    }
};