class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();++i)
            if(nums[i] == 0) c++;
        if(c>=2){
            vector<int> ans(nums.size(),0);
            return ans;
        }
        
        vector<int>left(nums.size(),0),right(nums.size(),0);
        int p = 1;
        for(int i=0;i<nums.size();++i)
        {
            left[i]=p;
            p*=nums[i];
        }
        p=1;
        for(int i=nums.size()-1;i>=0;--i)
        {
            right[i]=p;
            p*=nums[i];
        }
        // for(int i=0;i<nums.size();++i)
        //     cout<<left[i]<<" "<<right[i]<<endl;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();++i)
            ans[i]=left[i]*right[i];
        return ans;
    }
};