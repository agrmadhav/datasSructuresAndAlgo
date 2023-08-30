#include<iostream>
using namespace std;

int findmax(int A[],int n)
{
    int max = INT32_MIN;
    for(int i=0;i<n;i++)
    {
        if(A[i]>max)
        {
           max = A[i];
        }
    }
    return max;
}

void countSort(int A[],int n)
{
    int i,j,max,*C;

    max = findmax(A,n);
    C = new int[max+1];

    for(i=0;i<max+1;i++)
    {
        C[i] = 0;
    }
    for(i=0;i<n;i++)
    {
        C[A[i]]++;
    }

    i=0;j=0;
    while(j<max+1)
    {
        if(C[j]>0)
        {
            A[i++] = j;
            C[j]--;
        }
        else j++;
    }
}

int main()
{
    int A[] = {12,2,5,87,9,1,23,45,67,78,65};
    int n = 11;
    countSort(A,n);
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}