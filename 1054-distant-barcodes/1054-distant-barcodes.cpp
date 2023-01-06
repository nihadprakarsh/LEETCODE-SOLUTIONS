class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int,int> m;
        for(auto &it:barcodes)
        m[it]++;
        priority_queue<pair<int,int>> q;
        for(auto &it:m)
        q.push({it.second,it.first});
        vector<int> ans;
        while(!q.empty())
        {
            auto f1= q.top();
            q.pop();
            ans.push_back(f1.second);
            if(!q.empty()){
            auto f2=q.top();
            q.pop();
            if(f2.first-1>0)
            q.push({f2.first-1,f2.second});
            ans.push_back(f2.second);
            }
            if(f1.first-1>0)
            q.push({f1.first-1,f1.second});
        }
        return ans;
    }
};