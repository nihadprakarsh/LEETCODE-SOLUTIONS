class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> ans;
        for(int i=0;i<nums1.size();++i) ans.push_back((double)nums1[i]);
        for(int i=0;i<nums2.size();++i) ans.push_back((double)nums2[i]);
        sort(begin(ans),end(ans));
        if(ans.size()%2==1)
        return ans[ans.size()/2];
        else
        return (ans[ans.size()/2]+ans[ans.size()/2-1])/2;
    }
};