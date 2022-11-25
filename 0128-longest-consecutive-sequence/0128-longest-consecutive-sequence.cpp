class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(begin(nums), end(nums));
        vector<int> v(begin(st), end(st));
        int len = 0, maxLen =0 ;
        for(int i=0; i < v.size(); ++i)
        {
            if(i==0 || v[i]-v[i-1]<=1)
            {
                len++;
                maxLen = max(maxLen,len);
            }
            else
            len = 1;
        }
        return maxLen;
    }
};