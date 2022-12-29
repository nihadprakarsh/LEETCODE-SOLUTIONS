class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        size_t g = numsDivide[0], ans =0;
        for(int i=1;i < numsDivide.size();++i)
        g = gcd(g,numsDivide[i]);
        map<size_t,size_t> m;
        for(auto &it : nums) m[it]++;
        for(auto &it: m)
        {
            if(g%it.first==0)
            return ans;
            else
            ans+=it.second;
        }
        return -1;
    }
};