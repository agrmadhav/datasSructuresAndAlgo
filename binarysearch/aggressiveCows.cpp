#include<bits/stdc++.h>
using namespace std;

bool canplace(int arr[],int n,int cows,int dist){
    int coordinate = arr[0];
    int count = 1;
    for(int i=1;i<n;i++){
        if(arr[i]-coordinate >= dist){
            count++;
            coordinate = arr[i];
        }
        if(count == cows) return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,cows;
        cin >> n >> cows;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        sort(arr,arr+n);
        int low = 1;
        int high = arr[n-1] - arr[0];
        int res = -1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(canplace(arr,n,cows,mid) == true){
                res = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        cout << res << endl;
    }
    return 0;
}