class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int> m;
        vector<int> dp(arr.size(),1);
        for(int i=0;i<arr.size();++i)
        {
            if(m.count(arr[i]-difference))
            dp[i]+=m[arr[i]-difference];
            m[arr[i]]=dp[i];
        }
        return *max_element(begin(dp),end(dp));
    }
};