class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int> pre(arr.size(),0);
        int x=0,ans=0;
        for(int i=0;i<arr.size();++i)
        {
            pre[i]=x;
            x^=arr[i];
        }
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                for(int k=j;k<n;++k)
                {
                    int l=pre[j]^pre[i];
                    int r=pre[k]^pre[j]^arr[k];
                    if(l==r)
                    ans++;
                }
            }
        }
        return ans;
    }
};