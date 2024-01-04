class Solution {
public:
    long long mod= 1e9+7;
    long long dp[100001][3][2][2];
    long long find(int index, int n, int e, int l, int t){
        if(index==n){
 
            if(e>=2 && l>=1 && t>=1)return 1;
            else return 0;
        }
        if(dp[index][e][l][t]!=-1)return dp[index][e][l][t];

        long long pick=0;

        for(int i=0;i<26;i++){

            if(i==4 && e<2){
      
                pick= (pick +find(index+1,n,e+1,l,t))%mod;
            }

            else if(i==11 && l<1){


                pick= (pick +find(index+1,n,e,l+1,t))%mod;
            }
            else if(i==19 && t<1){
                pick= (pick +find(index+1,n,e,l,t+1))%mod;
            }
        
            else pick= (pick +find(index+1,n,e,l,t))%mod;
        }
        return dp[index][e][l][t] = pick;

    }
    int stringCount(int n) {
        memset(dp,-1,sizeof(dp));
        return (int)(find(0,n,0,0,0)%mod);
    }
};