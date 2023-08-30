#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class array
{
    private:
    int *A;
    int size;
    int length;
    void swap(int*x,int*y);

    public:
    array()
    {
        size =10;
        length =0;
        A = new int(size);
    }
    array(int sz)
    {
        size =sz;
        length =0;
        A = new int(size);
    }
    ~array()
    {
        delete[]A;
    }
void display();
void append(int x);
void insert(int index,int x);
int Delete(int index);
int get(int index);
};
void swap(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void array::display()
{
    for(int i=0;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
}

void array::append(int x)
{
    if(length < size){
    A[length]=x;
    length++;
    }
}

void array::insert(int index,int x)
{
    if(index>=0&&index<=length)
    {
        for(int i= length;i>index;i--)
        {
            A[i]=A[i-1];
        }
        A[index]=x;
        length++;
    }
}

int array::Delete(int index)
{
    int x = 0;
    if(index>=0 && index<length)
    {
        x = A[index];
        for(int i=index;i<length-1;i++)
        {
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
    return 0;
}
int array::get(int index)
{
    if(index>=0 && index<length)
    {
        return A[index];
    }
    return -1;
}


int main()
{
    return 0;
}