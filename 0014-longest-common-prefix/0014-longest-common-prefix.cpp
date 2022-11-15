class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = "";
        int j = 0;
        int finish = 0;
        if(strs.size() == 1){
            return strs[0];
        }
        while(true){
            int notadd = 0;
            int i = 1;
            while(i<strs.size()){
                if(strs[i-1].length() == 0 && strs[i].length()==0){
                    return str;
                }
                if(strs[i-1].length() <= j || strs[i].length() <= j){
                    finish = 1;
                    break;   
                }
                if(strs[i-1][j] != strs[i][j]){
                    notadd = 1;
                    break;
                }
                i++;
            }
            if(finish == 1)
                break;
            if(notadd == 0)
                str+=strs[i-1][j];
            else if(notadd == 1)
                break;
            j++;
            cout<<str<<" "<<j<<endl;
        }
        return str;
    }
};