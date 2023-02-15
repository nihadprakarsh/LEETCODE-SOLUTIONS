class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans(num.size());
        int i=num.size()-1,c=-1;
        while(i>=0)
        {
            int t=0;
            if(k)
            {
                t=k%10;
                k/=10;
            }
            int ct=num[i]+t;
            if(c!=-1) ct+=c;
            num[i]=ct%10;
            ct/=10;
            c=ct;
            i--;
        }
        while(k)
        {
            int t=k%10+c;
            k/=10;
            num.insert(num.begin(),t%10);
            t/=10;
            c=t;
        }
        if(c) num.insert(num.begin(),c);
        return num;
    }
};