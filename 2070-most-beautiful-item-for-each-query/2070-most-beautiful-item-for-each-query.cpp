class Solution {
public:
    int find(int amt, vector<vector<int>>&i)
    {
        int low=0,high=i.size()-1,mid,ans=0;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(i[mid][0] <= amt)
            {
                ans=i[mid][1];
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& item, vector<int>& q) {
        sort(begin(item),end(item));
        int tot=0;
        for(auto&i:item)
        {
            tot=max(tot,i[1]);
            i[1]=tot;
        }
        vector<int> ans(q.size(),0);
        for(int i=0;i < q.size(); i++)
        ans[i] = find(q[i],item);
        return ans;
    }
};