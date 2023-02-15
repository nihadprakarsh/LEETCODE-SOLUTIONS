class Solution {
public:
    long long countVowels(string word) {
        long long ans=0;
        for(int i=word.size()-1;i>=0;--i)
        {
            if(word[i]=='a' || word[i]=='e' || word[i]=='i'||word[i]=='o'||word[i]=='u')
            ans+=(word.size()-i)+((word.size()-(word.size()-i))*(word.size()-i));
        }
        return ans;
    }
};