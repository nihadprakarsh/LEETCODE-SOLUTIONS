class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool flag=true;
        for(;left<=right;++left)
        {
            bool temp=false;
            for(auto &it:ranges)
            if(left>=it[0]&&left<=it[1])
            temp=true;
            flag&=temp;
        }
        return flag;
    }
};