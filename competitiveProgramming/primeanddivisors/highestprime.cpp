#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<bool> isPrime(N,1);
vector<int> lowestPrime(N,0),highestPrime(N,0);
// time complexity of sieve - n/2+n/3 .... = O(nloglogn)

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i<N;i++){
        if(isPrime[i] == 1){
            lowestPrime[i] = highestPrime[i] = i;
            for(int j=2*i;j<N;j+=i){
                isPrime[j] = 0;
                highestPrime[j] = i;
                if(lowestPrime[j] == 0){
                    lowestPrime[j] = i;
                }
            }
        }
    }
}

int main(){
    sieve();
    for(int i=2;i<100;i++){
        cout<<lowestPrime[i]<<
        " "<<highestPrime[i]<<endl;
    }
    return 0;
}