#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct array
{
    int A[20];
    int size;
    int length;
};
void swap(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void display(struct array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        cout<<arr.A[i]<<" ";
    }
}

void append(struct array *arr,int x)
{
    if(arr->length<arr->size){
    arr->A[arr->length]=x;
    arr->length++;
    }
}

void insert(struct array *arr,int index,int x)
{
    if(index>=0&&index<=arr->length)
    {
        for(int i= arr->length;i>index;i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

int Delete(struct array *arr,int index)
{
    int x = 0;
    if(index>=0 && index<arr->length)
    {
        x = arr->A[index];
        for(int i=index;i<arr->length-1;i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}
int get(struct array arr,int index)
{
    if(index>=0 && index<arr.length)
    {
        return arr.A[index];
    }
    return -1;
}
void set(struct array*arr,int index,int x)
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index]=x;
    }
}
void reverse_auxillary(struct array *arr)
{
    int *B;
    int i,j;
    B = new int(arr->length);
    for(i=arr->length-1,j=0;i>=0;i--,j++)
    {
        B[j] = arr->A[i];
    }
    for(i=0;i<arr->length;i++)
    {
        arr->A[i] = B[i];
    }
}
void reverse2(struct array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}
void insert_in_sorted(struct array *arr,int x)
{
    int i= arr->length-1;
    if(arr->length == arr->size)
    {
        return;
    }
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}
int check_sort(struct array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {
            return 0;
        }
    }
        return 1;
}
void rearrange(struct array*arr)
{
    int i=0,j=arr->length-1;

    while(i<j)
    {
        while(arr->A[i]<0)
        {
            i++;
        }
        while(arr->A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}

struct array* merge(struct array*arr1,struct array *arr2)
{
    int i=0,j=0,k=0;
    struct array *arr3 = (struct array*)malloc(sizeof(struct array));

    while(i<arr1->length&& j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for(;j<arr2->length;j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length= arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

struct array* Union(struct array*arr1,struct array *arr2)
{
    int i=0,j=0,k=0;
    struct array *arr3 = (struct array*)malloc(sizeof(struct array));

    while(i<arr1->length&& j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for(;j<arr2->length;j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct array* Intersection(struct array*arr1,struct array *arr2)
{
    int i=0,j=0,k=0;
    struct array *arr3 = (struct array*)malloc(sizeof(struct array));

    while(i<arr1->length&& j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct array* Difference(struct array*arr1,struct array *arr2)
{
    int i=0,j=0,k=0;
    struct array *arr3 = (struct array*)malloc(sizeof(struct array));

    while(i<arr1->length&& j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

int main()
{
    int num;
    struct array arr={{2,3,5,6,7},20,5};

    display(arr);
    insert(&arr,3,67);
    Delete(&arr,4);
    display(arr);

cout<<endl<<endl;
    struct array arr1={{2,6,10,15,25},10,5};
    struct array arr2={{3,6,7,15,20},10,5};
    struct array *arr3;
    arr3 = merge(&arr1,&arr2);
    display(*arr3);
    return 0;
}