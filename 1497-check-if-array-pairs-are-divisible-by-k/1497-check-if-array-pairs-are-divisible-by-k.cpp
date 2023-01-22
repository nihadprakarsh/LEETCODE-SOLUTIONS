class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> m;
        for(auto &it:arr)
        m[((it%k)+k)%k]++;
        for(auto &it:m)
        {
            if(it.first==0)
            {
                if(it.second%2!=0)
                return false;
            }
            else if(m[k-it.first]!=it.second)
            return false;
        }
        return true;
    }
};