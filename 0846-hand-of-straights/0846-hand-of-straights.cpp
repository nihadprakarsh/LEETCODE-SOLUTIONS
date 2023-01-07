class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int> st(begin(hand),end(hand));
        int s=0,a=0;
        for(auto &it:st)
        {
            s++;
            a++;
            int prev=it;
            while(s<groupSize)
            {
                if(st.count(prev+1))
                {
                    st.erase(st.lower_bound(prev+1));
                    s++;
                    prev++;
                }
                else if(!st.count(prev+1))
                return false;
            }
            s=0;
        }
        return st.size()==a;  
    }
};