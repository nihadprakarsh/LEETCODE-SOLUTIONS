class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> v(31,0);
        for(auto it : candidates){
            for(int i=0 ; i <= 31; ++i)
                if((it & (1 << i)) != 0)
                v[i]++;
        }
        return *max_element(begin(v), end(v));
    }
};