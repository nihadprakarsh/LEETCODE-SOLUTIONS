class Solution {
public:
    vector<vector<string>> v;
    void getPartition(string &s, int ind, string temp, vector<string> vec)
    {
        if(ind == s.size())
        {
            vec.push_back(temp);
            v.push_back(vec);
            return;
        }
        
        if(temp.size())
        {
            vec.push_back(temp);
            string temp1 = "";
            temp1.push_back(s[ind]);
            getPartition(s,ind+1,temp1,vec);
            vec.pop_back();
        }
        temp.push_back(s[ind]);
        getPartition(s,ind+1,temp,vec);
    }
    
    bool isPallin(string &a)
    {
        string temp = a;
        reverse(begin(temp), end(temp));
        return temp == a;
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        getPartition(s,0,"",vec);
        vector<vector<string>> ans;
        for(auto &it: v)
        {
            bool flag = true;
            for(auto &str : it)
            {
                if(!isPallin(str))
                flag = false;
            }
            if(flag)
            ans.push_back(it);
        }
        return ans;
    }
};