class Solution {
public:
    int dp[1001][1001][4][3];
    int find(int ind, vector<int>&rating, int size, int flag, int prev)
    {
        if(size==0) return 1;
        if(ind >= rating.size()) return 0;
        if(dp[ind][prev+1][size][flag+1] != -1) return dp[ind][prev+1][size][flag+1];
        int a = 0, b = 0, c = 0;
        if(flag == -1)
        {
            a = find(ind+1,rating,size-1,1,ind);
            b = find(ind+1,rating,size-1,0,ind);
        }
        if(flag == 1 && rating[ind] > rating[prev])
        a =  find(ind+1,rating,size-1,flag,ind);
        if(flag == 0 && rating[ind] < rating[prev])
        b = find(ind+1,rating,size-1,flag,ind);
        c = find(ind+1,rating,size,flag,prev);
        return dp[ind][prev+1][size][flag+1] = a+b+c;
    }
    int numTeams(vector<int>& rating) {
        memset(dp, -1, sizeof(dp));
        return find(0,rating,3,-1,-1);
    }
};