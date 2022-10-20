class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> m;
        int i =0, j =0, c =0, ans = 0;
        while(j < nums.size())
        {
            if(nums[j]&1)
                c++;
            if(c==k)
                ans++;
            if(m.count(c-k))
                ans+=m[c-k];
            m[c]++;
            j++;
        }
        return ans;
    }
};