class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost =0, i =0, j =0, ans =0 ;
        while(j < s.size())
        {
            cost+=abs((s[j]-'a') - (t[j]-'a'));
            while(cost > maxCost){
                cost-=abs((s[i]-'a') - (t[i]-'a'));
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};