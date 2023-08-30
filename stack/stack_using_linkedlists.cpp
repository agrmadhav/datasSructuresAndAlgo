#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node*next;
}*top = NULL;

void push(int x)
{
    struct node*t;
    t= new node;

    if(t== NULL)
    {
        cout<<"stack overflow or heap is full"<<endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct node *t;
    int x = -1;
    if(top == NULL)
    {
        cout<<"stack is empty";
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}


int peek(int pos)
{
    int x = -1;
    struct node *p = top;
    for(int i=0;p!=NULL&& i<pos-1;i++)
    {
        p = p->next;
    }
    if(p!=NULL)
    return p->data;

    else
    return -1;

}

void Display()
{
    struct node *p = top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}



int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    cout<<pop()<<endl;

    Display();

    return 0;
}