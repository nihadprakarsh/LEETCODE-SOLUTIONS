class Solution {
public:
    int Getval(map<int,bool>&m,int key)
    {
        int ans =0 ;
        while(m.count(key))
        {
            ans++;
            key++;
        }
        return ans;
    }
    int longestConsecutive(vector<int>& nums) {
        map<int,bool> m;
        for(auto it : nums)
        m[it] = true;
        for(auto it:  nums)
        if(m.count(it-1))
        m[it] = false;
        
        int ans = 0;
        for(auto it : m)
        {
            if(it.second == true)
            ans = max(ans,Getval(m,it.first));
        }
        return ans;
    }
};