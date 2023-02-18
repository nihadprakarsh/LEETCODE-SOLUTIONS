class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        map<string,pair<multiset<char>,multiset<char>>> m;
        for(auto &word:words)
        {
            multiset<char> odd,even;
            for(int i=0;i<word.size();++i)
            {
                if(i%2) odd.insert(word[i]);
                else even.insert(word[i]);
            }
            m[word]={odd,even};
        }
        map<pair<multiset<char>,multiset<char>>,int> mp;
        for(auto &it:m) mp[it.second]++;
        return mp.size();
    }
};