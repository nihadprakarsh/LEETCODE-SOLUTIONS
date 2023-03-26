class Solution {
public:
    vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
    bool primeSubOperation(vector<int>& nums) {
        vector<int> sv=sieve(2000);
        set<int> st(begin(sv),end(sv));
        for(int i=0;i<nums.size();++i)
        {
            if(i==0)
            {
                auto it = st.lower_bound(nums[i]);
                if(*it>=nums[i])
                {
                    if(it!=st.begin())
                    --it;
                }
                if(*it<nums[i])
                nums[i]-=*it;
            }
            else
            {
                int diff = nums[i]-nums[i-1];
                auto it = st.lower_bound(diff);
                if(*it>=nums[i]-nums[i-1]) --it;
                // cout << diff << endl;
                if(nums[i]-*it>nums[i-1])
                nums[i]-=*it;
            }
        }
        // for(auto &it:nums) cout << it << " ";
        for(int i=0;i<nums.size()-1;++i)
        if(nums[i]>=nums[i+1]) return false;
        return true;
    }
};