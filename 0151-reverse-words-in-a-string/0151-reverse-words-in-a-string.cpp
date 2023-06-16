class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        vector<string> v; string temp = "";
        for(auto &it:s)
        {
            if((it>='a'&&it<='z')||(it>='A'&&it<='Z')||(it>='0'&&it<='9'))
                temp.push_back(it);
            else
            {
                if(temp.size())
                v.insert(v.begin(),temp);
                temp="";
            }
        }
        temp = "";
        for(auto &it:v)
            temp+=it+" ";
        temp.pop_back();
        return temp;
        
    }
};