#include<bits/stdc++.h>
using namespace std;

long long solve(long long temp,int k){
    if(temp == 0 || temp < k) return 0;
    long long res = temp-k+1;
    k++;
    while(k != temp+1){
        res += temp-k+1;
        k++;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,q;
        cin >> n >> k >> q;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        long long res=0,temp=0;
        for(int i=0;i<n;i++){
            if(arr[i] <= q) temp++;
            else{
                res = res + solve(temp,k);
                temp = 0;
            }
        }
        if(temp != 0){
            res = res + solve(temp,k);
        }
        cout << res <<endl;
    }
    return 0;
}