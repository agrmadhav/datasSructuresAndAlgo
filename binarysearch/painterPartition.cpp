#include<bits/stdc++.h>
using namespace std;

//User function template for C++

class Solution
{
    bool isvalid(int arr[],int n,int k,long long maxtime){
        int painters = 1;
        long long currtime = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > maxtime) return false;
            currtime += arr[i];
            if(currtime > maxtime){
                painters++;
                currtime = arr[i];
            }
            if(painters > k) return false;
        }
        return true;
    }
  public:
    long long minTime(int arr[], int n, int k)
    {
        // if(n < k) return -1;
        long long mx = -1;
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(arr[i] > mx){
                mx = arr[i];
            }
        }
        long long low = mx;
        long long high = sum;
        long long res = -1;
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(isvalid(arr,n,k,mid) == true){
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};