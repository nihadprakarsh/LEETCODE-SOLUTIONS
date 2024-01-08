class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(begin(nums1),end(nums1));        
        set<int> b(begin(nums2),end(nums2));
        set<int> common;
        for(auto i:a)
            if(b.count(i)) common.insert(i);
        int n = nums1.size(), n1 = a.size(), n2 = b.size(), c = common.size();
        return min(n, min(n1 - c, n / 2) + min(n2 - c, n / 2) + c);
    }
};