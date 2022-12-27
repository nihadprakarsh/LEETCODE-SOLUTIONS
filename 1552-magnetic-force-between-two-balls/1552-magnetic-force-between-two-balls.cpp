class Solution {
public:
    bool check(int mid, vector<int>&position, int m)
    {
        int prev=-1;
        for(int i=0;i<position.size();++i)
        {
            if(prev==-1||position[i]-prev>=mid)
            {
                prev=position[i];
                m--;
                if(m==0) break;
            }
        }
        return m==0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position),end(position));
        int low=0,high=INT_MAX,mid,ans;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(check(mid,position,m))
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};