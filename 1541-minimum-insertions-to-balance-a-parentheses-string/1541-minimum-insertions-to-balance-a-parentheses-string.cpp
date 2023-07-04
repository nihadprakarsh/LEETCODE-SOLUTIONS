class Solution {
public:
    int minInsertions(string s) {
        int res=0,c=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == '('){
                if(c%2>0)
                    c--,res++;
                c+=2;
            }
            else{
                c--;
                if(c<0) c+=2, res++;
            }
        }
        return res+c;
    }
};