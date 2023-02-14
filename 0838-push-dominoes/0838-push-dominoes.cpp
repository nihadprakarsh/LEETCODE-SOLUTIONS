class Solution {
public:
    string pushDominoes(string d) {
        vector<int> dp1(d.size(),0),dp2(d.size(),0);
        int l=0,r=0;
        for(int i=0;i<d.size();++i)
        {
            if(d[i]=='R') r=1;
            if(d[i]=='L' && r) r=0;
            if(d[i]=='.')
            {
                if(r)
                dp1[i]=r,r++;
            }
        }
        for(int i=d.size()-1;i>=0;--i)
        {
            if(d[i]=='L') l=1;
            else if(d[i]=='R' && l) l=0;
            else if(d[i]=='.')
            {
                if(l)
                dp2[i]=l,l++;
            }
        }
        // for(auto &it:dp1) cout << it << " "; cout << endl;
        // for(auto &it:dp2) cout << it << " "; cout << endl;
        cout << endl;
        for(int i=0;i<d.size();++i)
        {
            if(d[i]=='.')
            {
                // cout << dp1[i] << " " << dp2[i] << endl;
                if(dp1[i] && dp2[i])
                {
                    if(dp1[i]>dp2[i])
                    d[i]='L';
                    else if(dp1[i]<dp2[i])
                    d[i]='R';
                }
                else if(dp1[i])
                d[i]='R';
                else if(dp2[i])
                d[i]='L';
            }
        }
        return d;
    }
};