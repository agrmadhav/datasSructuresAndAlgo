#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 4;
    int W = 7;
    int wt[4] = {1,3,4,5};
    int val[4] = {1,4,5,7};

    int dp[n+1][W+1];
    memset(dp,-1,sizeof(dp));

    // initialisation using base condition;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }

    // n in recursion change to i and w in recursion to j

    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1]+ dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<< dp[n][W]<<endl;
    return 0;
}