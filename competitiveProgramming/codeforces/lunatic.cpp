#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int i=0,j=n-1;
        int ans = 0;
        while(i<j){
            ans = __gcd(ans,abs(arr[j]-arr[i]));
            i++;
            j--;
        }
        cout<<ans<<endl;
    }
    return 0;
}