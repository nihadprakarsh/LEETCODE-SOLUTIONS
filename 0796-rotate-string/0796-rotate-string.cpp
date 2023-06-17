class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=1;i<=goal.size();++i)
        {
            string t = goal;
            reverse(begin(t),end(t));
            reverse(t.begin(),t.begin()+i+1);
            reverse(t.begin()+i+1,t.end());
            // cout<<t<<endl;
            if(t==s) return true;
        }
        return false;
    }
};