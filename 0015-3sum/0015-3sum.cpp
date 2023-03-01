class Solution {
public:
    int find(int tar,vector<int>&nums,int i)
    {
        int low=i+1,high=nums.size()-1,mid;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(nums[mid]>tar)
            high=mid-1;
            else if(nums[mid]<tar)
            low=mid+1;
            else return mid;
        }
        return -1;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        set<vector<int>> ans;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                int k=find(-(nums[i]+nums[j]),nums,j);
                if(k!=-1)
                ans.insert({nums[i],nums[j],nums[k]});
            }
        }
        vector<vector<int>> v;
        for(auto &it:ans) v.push_back(it);
        return v;
    }
};