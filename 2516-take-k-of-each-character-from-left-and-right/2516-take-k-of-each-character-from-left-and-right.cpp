class Solution {
public:
    int takeCharacters(string s, int k) {
        int a=0,b=0,c=0;
        for(auto &it:s) 
        {
            if(it=='a') a++;
            else if(it=='b') b++;
            else c++;
        }
        if(a<k||b<k||c<k) return -1;
        map<char,int> m={{'a',a-k},{'b',b-k},{'c',c-k}};
        int i=0,j=0,ans=0;
        while(j<s.size())
        {
            m[s[j]]--;
            while(m[s[j]]<0&&i<=j)
            {
                m[s[i]]++;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return s.size()-ans;
    }
};