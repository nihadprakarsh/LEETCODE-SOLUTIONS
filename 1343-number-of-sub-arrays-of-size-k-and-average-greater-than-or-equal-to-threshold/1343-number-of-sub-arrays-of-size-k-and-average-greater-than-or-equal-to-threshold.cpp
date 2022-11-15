class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0;
        int j = k-1;
        double avg = 0;
        while(i<k){
            avg+=arr[i];
            i++;
        }
        double sum = avg;
        int count = 0;
        avg/=k;
        i = 1;
        j = i+k-1;
        if(avg>=threshold)
             count = 1;
        else  count = 0;
        while(j<arr.size()){
            sum-=arr[i-1];
            sum+=arr[j];
            if(sum/k >= threshold)
                count++;
            i++;
            j++;
        }
        return count;
    }
};