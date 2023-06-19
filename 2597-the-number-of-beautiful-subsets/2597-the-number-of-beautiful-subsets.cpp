class Solution {
public:
    bool check(int val,vector<int>&v,int k)
    {
        for(auto &it:v){
            if(it==val+k || it==val-k){
                return false;
            }
        }
        return true;
    }
    int find(vector<int>&nums,int k,vector<int>&v,int ind)
    {
        if(ind == nums.size()) return v.size() != 0;
        int a = 0;
        if(check(nums[ind],v,k))
        {
            v.push_back(nums[ind]);
            a+=find(nums,k,v,ind+1);
            v.pop_back();
        }
        a+=find(nums,k,v,ind+1);
        return a;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> v;
        return find(nums,k,v,0);
    }
};