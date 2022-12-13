class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int i =0, ans = 0;
        while(i < nums.size())
        {
            while(nums[i] == 0) i++;
            if(i >= nums.size()) break;
            int s = i, e = i, si =-1, ei = -1, c = 0;
            while(e < nums.size() && nums[e] != 0)
            {
                if(nums[e] < 0)
                {
                    if(si == -1)
                    si = e;
                    ei = e;
                    c++;
                }
                
                e++;
            }
            if(c%2==0) ans = max(ans,e-s);
            if(si != -1) ans = max(ans,e-si-1);
            if(ei != -1) ans = max(ans,ei-s);
            i = e+1;
        }
        return ans;
    }
};