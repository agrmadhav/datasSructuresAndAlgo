#include<bits/stdc++.h>
using namespace std;

void max_heapify(int arr[],int n,int i){
    int left = 2*i;
    int right = 2*i+1;
    int largest;
    if(left<=n && arr[left] > arr[i]){
        largest = left;
    }
    else{
        largest = i;
    }
    if(right<=n && arr[right] > arr[largest]){
        largest = right;
    }
    // checking if root node is the largest one or not
    if(largest != i){
        swap(arr[i],arr[largest]);
        max_heapify(arr,n,largest);
    }
}
void buildMax_heap(int arr[],int n){
    for(int i=n/2;i>=1;i--){
        max_heapify(arr,n,i);
    }
}
void heap_sort(int arr[],int n){
    int size = n;
    buildMax_heap(arr,n);
    for(int i=n;i>=2;i--){
        swap(arr[1],arr[i]);
        n--;
        max_heapify(arr,n,1);
    }
    n = size;
}
int main(){
    int heapsize = 10;
    int arr[heapsize+1];
    for(int i=1;i<=heapsize;i++)
        arr[i] = heapsize-i+1;
    // heap_sort(arr,heapsize);
    for(int i=1;i<=heapsize;i++) cout<<arr[i]<<" ";
    return 0;
}