class Solution {
public:
    bool check(int mid, string &ak, int k)
    {
        int t=0,f=0,i=0,j=0;
        while(j<ak.size())
        {
            if(ak[j]=='T') t++;
            else f++;
            if(j-i+1==mid)
            {
                if(t<=k || f<=k)
                return true;
                if(ak[i]=='T') t--;
                else f--;
                i++;
            }
            j++;
        }
        return false;
    }
    int maxConsecutiveAnswers(string ak, int k) {
        int low=0,high=INT_MAX,mid,ans;
        while(low<=high)
        {
            mid = (low+high)>>1;
            if(check(mid,ak,k))
            {
                low = mid+1;
                ans = mid;
            }
            else
            high = mid-1;
        }
        return ans;
    }
};