class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();++i)
            v.push_back({nums[i],i});
        sort(begin(v),end(v));
        int low=0,high=v.size()-1;
        while(low<=high)
        {
            int s = v[low].first+v[high].first;
            if(s==target)
                return {v[low].second,v[high].second};
            else if(s>target)
                high--;
            else
                low++;
        }
        return {};
    }
};