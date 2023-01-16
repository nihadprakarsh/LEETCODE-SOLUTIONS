class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n+1,0);
        for(auto &it:bookings)
        {
            v[it[0]-1]+=it[2];
            v[it[1]]-=it[2];
        }
        int s=0;
        for(int i=1;i<v.size();++i)
        v[i]=v[i]+v[i-1];
        v.resize(n);
        return v;
    }
};