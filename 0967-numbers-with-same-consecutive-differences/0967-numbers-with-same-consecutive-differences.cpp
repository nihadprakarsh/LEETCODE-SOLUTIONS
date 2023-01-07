class Solution {
public:
    vector<int>ans;
    void find(int sum,int n,int k)
    {
        if(n==0)
        {
            ans.push_back(sum);
            return;
        }
        for(int i=0;i<=9;++i)
        {
            if(sum==0)
            {
                if(i!=0){
                int k1=sum*10+i;
                find(k1,n-1,k);
                }
            }
            else
            {
                if(abs(sum%10-i)==k)
                {
                    int k1=sum*10+i;
                    find(k1,n-1,k);
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        find(0,n,k);
        return ans;
    }
};