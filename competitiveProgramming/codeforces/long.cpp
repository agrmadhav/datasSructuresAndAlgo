#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        long long sum = 0;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            sum += abs(arr[i]);
        }
        long long ans = 0;
        int i=0;
        while(i<n){
            if(arr[i] < 0){
                int j = i+1;
                while(j<n && arr[j]<=0){
                    j++;
                }
                ans++;
                i = j;
            }
            else i++;
        }
         cout << sum << " "<< ans << endl;
    }
}