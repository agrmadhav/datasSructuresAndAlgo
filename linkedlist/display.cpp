#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node*next;
}*first = NULL;


void create(int A[],int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first ->data = A[0];
    first ->next = NULL;
    last = first;

    for(int i=0;i<n;i++)
    {
        t = new Node;
        t ->data = A[i];
        t ->next = NULL;
        last ->next = t;
        last = t;
    }
}
// display iteratively

void display(struct Node*p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}
// display recursively

void Rdisplay(struct Node*p)
{
    if(p!= NULL)
    {
        cout<<p->data<<" ";
        display(p->next);
    }
}

int count(struct Node*p)
{
    int count =0;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}
int add(struct Node*p)
{
    if(p==0)
    {
        return 0;
    }
    else
    {
        return add(p->next)+p->data;
    }
}
// int max(struct Node*p)
// {
//     int max = INT32_MIN;

//     while(p)
//     {
//         if(p->data>max)
//         {
//             max = p->data;
//         }
//         p = p->next;
//     }
//     return max;
// }
int Rmax(struct Node*p)
{
    int x =0;

    if(p==0)
    return INT32_MIN;

    x= Rmax(p->next);

    if(x>p->data)
    return x;
    else return p->data;
}
struct Node* improve_search(struct Node*p,int key)
{
    struct Node*q;
    while(p!=NULL)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p = p->next;
    }
    return NULL;
}

void insert(struct Node*p,int index,int x)
{
    if(index <0 && index >count(p))
    {
        return;
    }  
    struct Node*t = new Node;
    t->data = x;

    if(index ==0)
    {
        t->next=first;
        first =t;
    }
    else
    {
        for(int i =0;i<index-1;i++)
        {
            p = p->next;   
        }
        t->next = p->next;
        p->next =t;
    }
}
void insert_last(int x)
{
    
}

void insert_sorted(struct Node *p ,int x)
{
    struct Node *t= new Node,*q=NULL;
    t->data = x;
    t->next = NULL;

    if(first == NULL)
    {
        first =t;
    }
    else
    {
        while(p&&p->data<x)
        {
            q=p;
            p = p->next;
        }
        if(p==first)
        {
            t->next = first;
            first =t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }

}
int main()
{
    int A[] ={3,4,5,6,7};
    create(A,10);
    insert_sorted(first,35);
    display(first);
    cout<<endl;
    Rdisplay(first);

    cout<<endl;
    cout<<count(first);
    cout<<endl;
    cout<<add(first)<<endl;
    return 0;

}