class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> st(begin(deadends), end(deadends));
        set<string> vis;
        queue<pair<string,int>> q;
        vis.insert("0000");
        q.push({"0000",0});
        while(!q.empty())
        {
            string str = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(st.count(str)) continue;
            if(str == target) return steps;
            for(int i=0; i < 4; ++i)
            {
                string temp = str;
                int dig = temp[i]-'0';
                if(dig == 0)
                {
                    temp[i] = '9';
                    if(!vis.count(temp)){
                    q.push({temp,steps+1});
                    vis.insert(temp);
                    }
                    temp[i] = '1';
                    if(!vis.count(temp)){
                    q.push({temp,steps+1});
                    vis.insert(temp);
                    }
                }
                else if(dig == 9)
                {
                    temp[i] = '8';
                    if(!vis.count(temp)){
                    q.push({temp,steps+1});
                    vis.insert(temp);
                    }
                    temp[i] = '0';
                    if(!vis.count(temp)){
                    q.push({temp,steps+1});
                    vis.insert(temp);
                    }
                }
                else
                {
                    temp[i] = (dig+1) + '0';
                    if(!vis.count(temp)){
                    q.push({temp,steps+1});
                    vis.insert(temp);
                    }
                    temp[i] = (dig-1) + '0';
                    if(!vis.count(temp)){
                    q.push({temp,steps+1});
                    vis.insert(temp);
                    }
                }
                
            }
            
        }
        return -1;
    }
};