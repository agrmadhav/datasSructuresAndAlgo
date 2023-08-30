#include <iostream>
using namespace std;
const int N = 1e5+10;
const int M = 1e9+7;
int fact[N];

// if m is prime then inverse of a is (a^m-2)%m;

int binaryexpo(int a,int b,int M){
	int res = 1;
	while(b > 0){
		if(b&1){
			res = (res * 1LL * a)%M;
		}
		a = (a * 1LL * a)%M;
		b >>= 1;
	}
	return res;
}

int main() {
	fact[0] = 1;
	for(int i=1;i<N;i++){
		fact[i] = (fact[i-1]* 1LL * i)%M;
	}
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int ans = fact[n];
		ans = (ans * 1LL * fact[k])%M;
		int den = (fact[k-n] * 1LL * fact[n])%M;
		ans = (ans * 1LL * binaryexpo(den,M-2,M))%M;
		cout<<ans<<endl;
	}
}