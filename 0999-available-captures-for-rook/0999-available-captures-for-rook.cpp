class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x,y;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j] == 'R'){
                    x=i;y=j;
                }
            }
        }
        int cnt=0;
        int i=x-1,j=y;
        while(i>=0){
            if(isupper(board[i][j]))
                break;
            if(board[i][j] == 'p'){
                cnt++;
                break;
            }
            i--;
        }
        i=x+1,j=y;
        while(i<8){
            if(isupper(board[i][j]))
                break;
            if(board[i][j] == 'p'){
                cnt++;
                break;
            }
            i++;
        }
        i=y-1,j=x;
        while(i>=0){
            if(isupper(board[j][i]))
                break;
            if(board[j][i] == 'p'){
                cnt++;
                break;
            }
            i--;
        }
        i=y+1,j=x;
        while(i<8){
            if(isupper(board[j][i]))
                break;
            if(board[j][i] == 'p'){
                cnt++;
                break;
            }
            i++;
        }
        return cnt;
    }
};