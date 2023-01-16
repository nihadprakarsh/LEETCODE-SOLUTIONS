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
        for(int i=0;i<v.size();++i)
        {
            s+=v[i];
            v[i]=s;
        }
        v.resize(n);
        return v;
    }
};