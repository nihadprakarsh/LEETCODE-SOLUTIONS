class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int s=0,ans=0,mod=1e9+7;
        int p[]={1,0};
        for(int i=0;i<arr.size();++i)
        {
            s+=arr[i];
            p[s%2]++;
            if(s%2==0)
            ans=(ans+p[1])%mod;
            else
            ans=(ans+p[0])%mod;
        }
        return ans;
    }
};