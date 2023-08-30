#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first = new Node;
    first->data=A[0];
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = new Node;
        t->data=A[i];
        t->next = NULL;
        last->next = t;
        last =t;
    }
}

void display(struct Node*p)
{
    while(p!= NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}
void reverse_display(struct Node*p)
{
    if(p!= NULL)
    {
        reverse_display(p->next);
        cout<<p->data<<" ";
    }
}
int count(struct Node*p)
{
    int count=0;
    while(p!= NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

int max(struct Node*p)
{
    int m= INT32_MIN;
    while(p!=NULL)
    {
        if(p->data>m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

int sum(struct Node*p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum += p->data;
        p= p->next;
    }
    return sum;
}
int del(struct Node *p,int index)
{
    struct Node*q =NULL;
    int x=-1,i;

    if(index<1||index>count(p))
    {
        return -1;
    }
    if(index==1)
    {
        q=first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next= p->next;
        x= p->data;
        delete p;
        return x;
    }
}
int main()
{
    struct Node *temp;
    int A[] = {3,5,7,10,25,8,32,2};
    create(A,8);

    display(first);

    cout<<endl;
    cout<<count(first)<<endl;

    cout<<sum(first)<<endl;
    cout<<max(first)<<endl;

    del(first,4);
    display(first);
    return 0;
}