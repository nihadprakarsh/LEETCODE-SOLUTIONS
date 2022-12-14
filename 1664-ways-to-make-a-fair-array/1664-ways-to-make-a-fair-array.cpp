class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> prefix(n), suffix(n);
        int o = 0, e = 0;
        for(int i =0 ; i < nums.size(); ++i)
        {
            prefix[i] = {o,e};
            if(i%2) e+=nums[i];
            else o+=nums[i];
        }
        
        o=0,e=0;
        for(int i = nums.size()-1; i>=0; --i)
        {
            suffix[i] = {o,e};
            if(i%2) e+=nums[i];
            else o+=nums[i];
        }
        
        int ans =0 ;
        for(int i =0 ; i < nums.size(); ++i)
        {
            int sum1 = prefix[i].first + suffix[i].second;
            int sum2 = prefix[i].second + suffix[i].first;
            if(sum1==sum2) ans++;
        }
        return ans;
    }
};