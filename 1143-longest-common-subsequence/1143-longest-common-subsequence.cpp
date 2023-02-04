class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> cur(1001,0),prev(1001,0);
        for(int ind1 = text1.size()-1; ind1 >=0 ; --ind1)
        {
            for(int ind2 = text2.size()-1; ind2>=0; ind2--)
            {
                int a =0 , b =0 ;
                if(text1[ind1] == text2[ind2])
                a = 1 + prev[ind2+1];
                b = max(prev[ind2],cur[ind2+1]);
                cur[ind2] = max(a,b);
            }
            prev=cur;
        }
        return prev[0];
    }
};