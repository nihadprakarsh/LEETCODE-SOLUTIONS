class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double i=0,j=0;
        double n=nums.size();
        double avg=INT_MIN,sum=0;
        while(j<n)
        {
            sum+=nums[j];
            if((j-i+1)==k)
            {   
                 avg = max(avg,sum/k);
                 sum-=nums[i];
                i++;
             
            }
            j++;
        }
       return avg;
    }
};