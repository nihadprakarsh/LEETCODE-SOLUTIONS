class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> st(begin(arr),end(arr));
        int ans=0;
        for(int i=0;i<arr.size();++i)
        {
            for(int j=i+1;j<arr.size();++j)
            {
                int a=arr[i],b=arr[j],l=2;
                if(!st.count(a+b)) continue;
                while(st.count(a+b))
                l++,b=a+b,a=b-a;
                ans=max(ans,l);
            }
        }
        return ans;
    }
};