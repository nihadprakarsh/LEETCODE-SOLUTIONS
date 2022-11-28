class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int,int> m;
        for(auto it : rectangles)
        {
            m[min(it[0],it[1])]++;
        }
        int min = 0, sz = 0;
        return m.rbegin()->second;
    }
};