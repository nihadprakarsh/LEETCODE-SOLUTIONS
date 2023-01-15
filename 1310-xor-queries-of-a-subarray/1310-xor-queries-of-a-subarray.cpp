class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n=arr.size();
        vector<int> xorr(n,0);
        int x=0;
        for(int i=0; i<arr.size();++i)
        {
            xorr[i]=x;
            x^=arr[i];
        }
        vector<int> ans(q.size(),0);
        for(int i=0;i<q.size();++i)
            ans[i]=(arr[q[i][1]]^xorr[q[i][1]])^xorr[q[i][0]];
        return ans;
    }
};