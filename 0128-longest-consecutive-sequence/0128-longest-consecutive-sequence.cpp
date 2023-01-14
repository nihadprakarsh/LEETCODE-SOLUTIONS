class Solution {
public:
    int ans=0;
    int find(map<int,bool>&m, int x)
    {
        int a=1;
        while(1)
        {
            if(m.count(x+1))
            {
                x++;
                a++;
            }
            else
            break;
        }
        return a;
    }
    int longestConsecutive(vector<int>& nums) {
        map<int,bool> m;
        for(auto &it:nums) m[it]=true;
        for(auto &it:m)
        {
            if(m.count(it.first-1))
            m[it.first]=false;
        }
        for(auto &it:m)
        {
            if(it.second==true)
            ans=max(ans,find(m,it.first));
        }
        return ans;
    }
};