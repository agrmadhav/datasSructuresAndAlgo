#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[],int n){
    int j;
    int x;
    for(int i=1;i<n;i++){
        j = i-1;
        x = arr[i];

        while(arr[j] > x && j>-1){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}
void selectionSort(int arr[],int n){
    int j,k,i;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(arr[j]<arr[k]){
                k = j;
            }
            swap(arr[i],arr[k]);
        }
    }
}

int main(){
    int arr[] = {1,12,3,25,45,32,26,78,123};
    int n = 9;
    // bubbleSort(arr,n);
    // insertionSort(arr,n);
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
    return 0;
}