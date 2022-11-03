class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> v;
        for(int i=0 ; i < capacity.size(); ++i)
            v.push_back(capacity[i]-rocks[i]);
        sort(begin(v), end(v));
        int c = 0;
        for(int i =0;  i < v.size(); ++i){
            if(v[i] > additionalRocks)
                break;
            c++;
            additionalRocks-=v[i];
        }
        return c;
    }
};