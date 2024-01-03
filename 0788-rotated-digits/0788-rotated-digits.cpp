class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i=1;i<=n;++i)
        {
            bool flg=true,flg1=false, flg2=false;
            int tmp = i;
            while(tmp)
            {
                int d = tmp%10;
                if(d==3 || d==4 || d==7)
                    flg=false;
                else if(d==0 || d==1 || d==8)
                    flg1=true;
                else
                    flg2=true;
                tmp/=10;
            }
            if(flg && ((flg1 && flg2) || (flg2 && !flg1)))
                ans++;
        }
        return ans;
    }
};