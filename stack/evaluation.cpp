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
    t= (struct node*)malloc(sizeof(struct node));

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
    int x= -1;
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
int pre(char x)
{
    if(x=='+' || x=='-')
    return 1;

    else if(x=='*' || x=='/')
    return 2;

    return 0;
}
int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x =='/')
    return 0;
    else
    return 1;
}

int eval(char*postfix)
{
    int i=0;
    int x1,x2,r;

    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i] -'0');
        }
        else
        {
            x2= pop();
            x1=pop();

            switch(postfix[i])
            {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            push(r);
        }
    }
    return top->data;
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
    char*postfix = "234*+82/-";
    cout<<eval(postfix)<<endl;
    return 0;
}