class Solution {
public:
    set<pair<int,int>> indices;
    bool find(set<int>&st, vector<int>&stones,int ind,int jump){
        if(!st.count(ind) || indices.count({ind,jump}))
            return false;
        if(ind == stones[stones.size()-1])
            return true;
        indices.insert({ind,jump});
        bool flag = false;
        if(ind == 0)
            flag = flag || find(st,stones,ind+1,1);
        else
        {
            for(int i = -1; i <= 1; ++i){
                flag = flag || find(st,stones,ind+(jump+i),jump+i);
            }
        }
        return flag;
    }
    bool canCross(vector<int>& stones) {
        set<int> st;
        for(auto it : stones) st.insert(it);
        return find(st,stones,0,-1);
    }
};