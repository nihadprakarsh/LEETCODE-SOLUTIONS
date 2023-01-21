class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m;
        for(auto &it:arr) m[it]++;
        vector<int> v; 
        for(auto &it:m) v.push_back(it.second);
        sort(begin(v),end(v));
        for(int i=0;i<v.size();++i)
        {
            if(v[i]>k)
            {
                k-=v[i];
                break;
            }
            else
            {
                k-=v[i];
                v[i]=0;
                if(k==0) break;
            }
        }
        int c=0;
        for(int i=0;i<v.size();++i) if(v[i]) c++;
        return c;
    }
};