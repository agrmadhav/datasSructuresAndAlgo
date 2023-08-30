#include<bits/stdc++.h>
using namespace std;
// time complexity O(2^n)
int knapsack(int n, int wt[],int val[],int W){
    if( n == 0 || W == 0){
        return 0;
    }
    if(wt[n-1] <= W){
        return max(val[n-1] + knapsack(n-1,wt,val,W - wt[n-1]),
        knapsack(n-1,wt,val,W));
    }
    return knapsack(n-1,wt,val,W);
}
// now using memoization
int dp[102][1002];

int knapsackMemoization(int n,int wt[],int val[],int W){

    for(int i=0;i<102;i++){
    for(int j=0;j<1002;j++){
        dp[i][j] = -1;
    }
}
    if(n == 0 || W == 0){
        return 0;
    }
    if(dp[n][W] != -1){
        return dp[n][W];
    }
    if(wt[n-1] <= W){
        return dp[n][W] = max(val[n-1] + knapsack(n-1,wt,val,W - wt[n-1]),
        knapsack(n-1,wt,val,W));
    }
    return dp[n][W] = knapsack(n-1,wt,val,W);

}

int main(){
    int n = 4;
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    int W = 7;
    cout<< knapsack(n,wt,val,W)<<endl;
    cout<< knapsackMemoization(n,wt,val,W)<<endl;
    return 0;
}

