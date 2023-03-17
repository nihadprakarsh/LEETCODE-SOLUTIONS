class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,priority_queue<int>> m;
        for(int i=0;i<nums.size();++i)
        {
            int temp=nums[i];
            int s=0;
            while(temp)
            {
                s+=temp%10;
                temp/=10;
            }
            m[s].push(nums[i]);
        }
        int res=-1;
        for(auto &it:m)
        {
            if(it.second.size()>=2)
            {
                auto q=it.second;
                auto i=q.top(); q.pop();
                auto j=q.top(); q.pop();
                res=max(res,i+j);
            }
        }
        return res;
    }
};