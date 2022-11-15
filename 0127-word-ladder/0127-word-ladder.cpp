class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(begin(wordList), end(wordList));
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string str = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(str == endWord) return steps;
            for(int i=0; i < str.size(); ++i)
            {
                char original = str[i];
                    for(char ch = 'a' ; ch <= 'z' ; ++ch)
                    {
                    str[i] = ch;
                    if(st.count(str)){
                        q.push({str,steps+1});
                        st.erase(st.lower_bound(str));
                    }
                }
                str[i] = original;
            }
        }
        return 0;
    }
};