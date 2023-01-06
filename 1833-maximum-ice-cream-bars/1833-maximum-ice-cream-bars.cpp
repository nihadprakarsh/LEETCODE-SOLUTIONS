class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs),end(costs));
        int c=0,ans=0;
        for(int i=0; i < costs.size(); ++i)
        {
            c+=costs[i];
            if(c>coins)
            return ans;
            ans++;
        }
        return ans;
    }
};