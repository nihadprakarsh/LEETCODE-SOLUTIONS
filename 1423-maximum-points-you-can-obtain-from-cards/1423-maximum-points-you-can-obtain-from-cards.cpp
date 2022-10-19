class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> v;
        for(int i = n-k; i < n; ++i)
            v.push_back(cardPoints[i]);
        for(int i =0 ; i < k; ++i)
        {
            // if(i == init)
            //     break;
            v.push_back(cardPoints[i]);
        }
        
        int sum = 0, ans = 0, i =0, j =0;
        while(j < v.size())
        {
            sum+=v[j];
            if(j-i+1 == k)
            {
                ans = max(ans,sum);
                sum-=v[i++];
            }
            j++;
        }
        return ans;
    }
};