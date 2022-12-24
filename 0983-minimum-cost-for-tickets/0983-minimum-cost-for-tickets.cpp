class Solution {
public:
    int dp[366];
    int find(vector<int>&days, int ind, vector<int>&costs)
    {
        if(ind >= days.size()) return 0;
        int a = 0, b = 0 , c = 0;
        if(dp[ind] != -1) return dp[ind];
        a = costs[0] + find(days,ind+1,costs);
        int i = ind;
        for(; i < days.size(); ++i)
        {
            if(days[i] >= days[ind] + 7)
            break;
        }
        
        b = costs[1] + find(days,i,costs);
        
        i = ind;
        for(; i < days.size(); ++i)
        {
            if(days[i] >= days[ind] + 30)
            break;
        }
        
        c = costs[2] + find(days,i,costs);
        
        return dp[ind] = min(a,min(b,c));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return find(days,0,costs);
    }
};