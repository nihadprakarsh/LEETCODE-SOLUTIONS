class Solution {
public:
    int find(string &word,int ind,int counter)
    {
        if(ind == word.size()) return 0;
        int a = 0;
        if(counter%3 == 1){
            if(word[ind] == 'a')
                a+=find(word,ind+1,(counter+1)%3);
            else
                a+=1+find(word,ind,(counter+1)%3);
        }
        else if(counter%3 == 2){
            if(word[ind]=='b')
                a+=find(word,ind+1,(counter+1)%3);
            else
                a+=1+find(word,ind,(counter+1)%3);
        }
        else if(counter%3 == 0){
            if(word[ind] == 'c')
                a+=find(word,ind+1,(counter+1)%3);
            else
                a+=1+find(word,ind,(counter+1)%3);
        }
        return a;
        
    }
    int addMinimum(string word) {
        int res = find(word,0,1);
        if(word.back() == 'c')
            return res;
        else if(word.back() == 'b')
            return res+1;
        else 
            return res+2;
    }
};