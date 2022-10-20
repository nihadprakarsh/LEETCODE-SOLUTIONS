class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i= 0, j =0, ans =0, sum=0;
        map<int,int> m;
        while(j < nums.size())
        {
            sum+=nums[j];
            if(sum == goal)
            ans++;
            if(m.count(sum-goal))
                ans+=m[sum-goal];
            m[sum]++;
            j++;
        }
        return ans;
    }
};