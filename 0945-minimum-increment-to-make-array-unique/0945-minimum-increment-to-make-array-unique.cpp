class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int> m;
        int l=-1,r=-1;
        for(auto &it:nums) m[it]++;
        int ans=0;
        for(auto &it:m)
        {
            int freq=it.second;
            if((l==-1&&r==-1)||(it.first>r))
            {
                int k1=freq-1;
                ans+=(k1*(k1+1))/2;
                l=it.first,r=it.first+k1;
            }
            else
            {
                int a1=(r-it.first+1)*freq;
                int k1=freq-1;
                ans+=(k1*(k1+1))/2+a1;
                l=it.first,r+=k1+1;
            }
        }
        return ans;
    }
};