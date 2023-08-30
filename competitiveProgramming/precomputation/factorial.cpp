#include<bits/stdc++.h>
using namespace std;
const int M  = 1e9+7;
const int N = 1e5+10;
long long fact[N];

// 1=<t<=10^5
// 1=<n<=10^5
// o(t*n)
int main(){
    fact[0] = fact[1] = 1;
    for(int i=2;i<=N;i++){
        fact[i] = (fact[i-1]*i)%M;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<fact[n]<<endl;
        // time complexity o(T)
    }
    // while(t--){
    //     int n ;
    //     cin>>n;
    //     long long fact = 1;
    //     for(int i=2;i<=n;i++){
    //         fact = (fact*i)%M;
    //     }
    //     cout<<fact<<endl;
    // }
    // this solution will give tle
    return 0;
}