class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> ans(m,0);
        for(int i =0 ; i < queries.size(); ++i)
        {
            int x = queries[i][0], y = queries[i][1];
            int ans1 = 0;
            while(x!=y)
            {
                if(x>y) x/=2;
                else y/=2;
                ans1++;
            }
            ans[i] = ans1+1;
        }
        return ans;
    }
};