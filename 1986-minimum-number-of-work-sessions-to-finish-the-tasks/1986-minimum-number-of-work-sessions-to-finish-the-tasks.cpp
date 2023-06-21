class Solution {
public:
    int dp[1<<14][20];
    int find(vector<int>&tasks,int vis,int timeSpent,int time)
    {
        if(__builtin_popcount(vis) == tasks.size()) return 0;
        if(dp[vis][timeSpent]!=-1) return dp[vis][timeSpent];
        int a = 1e9;
        for(int i=0;i<tasks.size();++i)
        {
            if(((1<<i)&vis) == 0)
            {
                if(timeSpent-tasks[i]>=0)
                {
                    int temp = vis;
                    vis|=1<<i;
                    a=min(a,find(tasks,vis,timeSpent-tasks[i],time));
                    vis=temp;
                }
                else
                {
                    int temp = vis;
                    vis|=1<<i;
                    a=min(a,1+find(tasks,vis,time-tasks[i],time));
                    vis=temp;
                }
            }
        }
         return dp[vis][timeSpent]=a;
        
        
    }
    int minSessions(vector<int>& tasks, int time) {
        memset(dp,-1,sizeof(dp));
        return 1+find(tasks,0,time,time);
    }
};