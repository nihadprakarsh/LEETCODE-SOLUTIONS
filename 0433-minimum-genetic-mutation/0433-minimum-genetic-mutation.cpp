class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st(begin(bank), end(bank));
        set<string> vis;
        queue<pair<string,int>> q;
        vis.insert(startGene);
        q.push({startGene,0});
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto str = q.front().first;
                int steps = q.front().second;
                q.pop();
                if(str==endGene) return steps;
                string t = "";
                for(int i=0; i < 8; ++i)
                {
                    t = str;
                    t[i]='A';
                    if(st.count(t) && !vis.count(t)) { q.push({t,steps+1}); vis.insert(t);}
                    t[i]='C';
                    if(st.count(t) && !vis.count(t)) { q.push({t,steps+1}); vis.insert(t);}
                    t[i]='G';
                    if(st.count(t) && !vis.count(t)) { q.push({t,steps+1}); vis.insert(t);}
                    t[i]='T';
                    if(st.count(t) && !vis.count(t)) { q.push({t,steps+1}); vis.insert(t);}
                }
            }
        }
        return -1;
    }
};