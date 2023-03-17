class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums1.size();++i)
        v.push_back({nums2[i],nums1[i]});
        sort(v.rbegin(),v.rend());
        long long s=0,res=0;
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<k-1;++i)
        {
            s+=v[i].second;
            q.push(v[i].second);
        }
        for(int i=k-1;i<nums1.size();++i)
        {
            s+=v[i].second;
            q.push(v[i].second);
            res=max(res,s*v[i].first);
            s-=q.top();
            q.pop();
        }
        return res;
    }
};