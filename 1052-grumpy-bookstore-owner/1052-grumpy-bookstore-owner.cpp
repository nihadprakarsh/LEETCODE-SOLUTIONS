class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans =0 ;
        for(int i =0; i < customers.size();++i)
            if(!grumpy[i])
                ans+=customers[i];
        int k = minutes, i =0, j =0, ans1 =0, sum =0;
        while(j < customers.size())
        {
            if(grumpy[j])
                sum+=customers[j];
            if(j-i+1==k)
            {
                ans1=max(ans1,sum);
                if(grumpy[i])
                    sum-=customers[i];
                i++;
            }
            j++;
        }
        return ans+ans1;
    }
};