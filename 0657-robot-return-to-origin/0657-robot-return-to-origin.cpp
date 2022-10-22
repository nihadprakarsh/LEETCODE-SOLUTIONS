class Solution {
public:
    bool judgeCircle(string moves) {
        map<char,int> m = {{'U',2}, {'D',-2}, {'L',2}, {'R',-2}};
        pair<int,int> ans = {0,0};
        for(auto it: moves)
        {
            if(it == 'U' || it == 'D')
                ans.first+=m[it];
            else
                ans.second+=m[it];
        }
        return ans.first ==0 && ans.second ==0;
    }
};