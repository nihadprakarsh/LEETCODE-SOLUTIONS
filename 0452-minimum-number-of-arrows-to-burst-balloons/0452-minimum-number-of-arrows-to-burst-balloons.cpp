class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points),end(points));
        int ans=0,l=-1,r=-1;
        for(auto &it:points)
        {
            if(l==-1 && r==-1)
            {
                ans++;
                l=it[0]; r=it[1];
            }
            else if(it[0]>=l && it[0]<=r)
            r=min(r,it[1]);
            else if(it[0]>r)
            {
                ans++;
                l=it[0];
                r=it[1];
            }
        }
        return ans;
    }
};