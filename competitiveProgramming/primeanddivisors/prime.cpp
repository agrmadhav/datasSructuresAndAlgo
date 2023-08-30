#include<bits/stdc++.h>
using namespace std;

// imp property -> root(n) se pehle ek prime number exist krta hi hai har ek composite number ke liye

int main(){
    int n;
    cin>>n;
    vector<int>primes;
    for(int i=2;i*i<=n;i++){
        while(n%i == 0){
            primes.push_back(i);
            n /= i;
        }
    }
    if(n>1) primes.push_back(n);// agar ek akela prime bach jaaye
    // O(n) - > O(root(n))
    for(int prime : primes){
        cout << prime << " " ;
    }
}