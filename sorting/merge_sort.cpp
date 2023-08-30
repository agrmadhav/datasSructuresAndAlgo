#include<iostream>
using namespace std;

void Merge(int A[],int l,int mid,int h)
{
    int i,j,k;
    i =l; j = mid+1; k = l;

    int B[h+1];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else{
            B[k] = A[j];
            k++;
            j++;
        }
    }
        for( ; i<=mid;i++)
        {
            B[k] = A[i];
            k++;
        }
        for( ; j<=h;j++)
        {
            B[k] = A[j];
            k++;
        }
        for(int i =l;i<=h;i++)
        {
            A[i] = B[i];
        }
}


void recMergeSort(int A[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid = (l+h)/2;
        recMergeSort(A,l,mid);
        recMergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

int main()
{
    int A[] = {12,2,5,87,9,1,23,45,67,78,65};
    int n = 11;
    // itMergeSort(A,n);
    recMergeSort(A,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}



void itMergeSort(int A[], int n)
{
    int p,l,mid,h,i;

    for(p = 2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A,l,mid,h);
        }
        if(n-i>p/2)
        {
            l =i;
            h= i+p-1;
            mid= (l+h)/2;
            Merge(A,l,mid,n-1);
        }
    }
    if(p/2<n)
    {
        Merge(A,0,p/2-1,n-1);
    }
}
