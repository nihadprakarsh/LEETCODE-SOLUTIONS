class Solution {
public:
    static bool comp(pair<int,int>&a, pair<int,int>&b)
    {
        if(a.second == b.second)
        return a.first < b.first;
        return a.second < b.second;
    }
    set<int> st;
    int getPow(int i,int steps)
    {
        if(i==1)
        return 0;
        if(st.count(i)) -1e8;
        st.insert(i);
        int a= 0,b=0;
        if(i%2) a = 1 + getPow(3*i+1,steps+1);
        else b= 1 + getPow(i/2,steps+1);
        return max(a,b);
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v;
        for(int i= lo; i <= hi; ++i)
        {
            st.clear();
            v.push_back({i,getPow(i,0)});
        }
        
        sort(begin(v), end(v), comp);
        return v[k-1].first;
    }
};