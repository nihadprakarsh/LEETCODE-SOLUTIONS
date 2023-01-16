class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(begin(intervals),end(intervals));
        vector<int> flag(intervals.size(),true);
        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i][0]>=intervals[i-1][0] && intervals[i][0]<=intervals[i-1][1])
            {
                intervals[i-1][1]=max(intervals[i-1][1],intervals[i][1]);
                swap(intervals[i],intervals[i-1]);
                flag[i-1]=false;
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();++i)
        if(flag[i]) ans.push_back(intervals[i]);
        return ans;
    }
};