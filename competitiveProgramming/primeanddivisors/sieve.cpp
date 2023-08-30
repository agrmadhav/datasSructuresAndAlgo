// Q - 10^7
// N - 10^7;
// TELL WHETHER NUMBER IS PRIME OR NOT
#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<bool> isPrime(N,1);
// time complexity of sieve - n/2+n/3 .... = O(nloglogn)

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i<N;i++){
        if(isPrime[i] == 1){
            for(int j=2*i;j<N;j+=i){
                isPrime[j] = 0;
            }
        }
    }
}

int main(){
    sieve();
    int q;
    cin >> q;
    while(q--){
        int n;
        cin>>n;
        if(isPrime[n]==1) cout<<"prime"<<endl;
        else cout<<"notprime"<<endl;
    }
    return 0;
}