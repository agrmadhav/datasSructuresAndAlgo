#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int arr[N+1];
int prefixsum[N+1];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        prefixsum[i] = prefixsum[i-1] + arr[i];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<prefixsum[r]-prefixsum[l-1]<<endl;
    }
}