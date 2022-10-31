class Solution {
public:
    int partitionString(string s) {
        map<char,int> m;
        int c =0 ;
        for(auto it : s)
        {
            m[it]++;
            if(m[it] > 1){
                m.erase(begin(m), end(m));
                c++;
                m[it]++;
            }
        }
        if(m.size())
            c++;
        return c;
    }
};