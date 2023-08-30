#include<bits/stdc++.h>
using namespace std;
//User function template in C++

class Solution 
{
    bool isvalid(int A[],int N,int M,int mx){
        int student = 1;
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(sum > mx){
                student++;
                sum = A[i];
            }
            if(student > M) return false;
        }
        return true;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N < M) return -1;
        int sum = 0;
        int mx = -1;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(A[i] > mx) mx = A[i];
        }
        int low = mx;
        int high = sum;
        int res = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isvalid(A,N,M,mid) == true){
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};