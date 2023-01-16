class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(2000,0);
        for(auto &it:trips)
        {
            v[it[1]]+=it[0];
            v[it[2]]-=it[0];
        }
        int s=0;
        for(int i=0;i<v.size();++i)
        {
            s+=v[i];
            if(s>capacity)
            return false;
        }
        return true;
    }
};