class Solution {
public:
double findMaxAverage(vector<int>& nums, int k) {
        double i=0,j=0,sum=0;
        double n=nums.size();
        double avg=INT_MIN;
        while(j<n)
        {
            sum+=nums[j];
            if((j-i+1)==k)
            {   
                 avg = max(avg,sum);
                 sum-=nums[i];
                i++;
             
            }
            j++;
        }
       return avg/k;
    }
};