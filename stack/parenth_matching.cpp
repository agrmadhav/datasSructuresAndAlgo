#include<iostream>
using namespace std;

struct node
{
    char data;
    struct node*next;
}*top = NULL;

void push(char x)
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

char pop()
{
    struct node *t;
    char x= -1;
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


char peek(int pos)
{
    char x = -1;
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



int isBalanced(char *exp)
{
    int i;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i] == '(')
        {
            push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            if(top == NULL)
            return 0;
            else
            pop();
        }
    }
    if(top == NULL)
    return 1;
    else
    return 0;
}


int main()
{
    char* exp = "((a+b)*(c-d))";
    cout<<isBalanced(exp)<<endl;
    return 0;
}