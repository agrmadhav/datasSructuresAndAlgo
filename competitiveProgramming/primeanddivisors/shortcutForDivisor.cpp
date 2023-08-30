// x = p1^n1 * p2^n2 * p3^n3
//no of divisors = (n1+1)*(n2+1)*(n3+1)
// sum of divisors = (p1^0+p1^1...+p1^n1)(p2^0+p2^1+p2^2)........
// === ((p1^n1+1 - 1)/p1-1)*((p2^n1+1 - 1)/p2-1)...................


// so we find the prime numbers and then find the number of divisor and sum of divisors using this formula

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> divisors[N];
vector<int>sum(N,0);
// time complexity of sieve - n/2+n/3 .... = O(nloglogn)

void sieve(){
    // O(nlogn)
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            divisors[j].push_back(i);
            sum[j]+=i;
        }
    }
}

int main(){
    sieve();
    for(int i=2;i<100;i++){
        cout<<"the sum of divisors is "<<sum[i]<<" and the divisors are : ";
        for(int div:divisors[i]){
            cout<<div<<" ";
        }
        cout<<endl;
    }
    return 0;
}
