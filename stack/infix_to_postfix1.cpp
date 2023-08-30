#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


struct node
{
    char data;
    struct node*next;
}*top = NULL;

void push(char x)
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

char pop()
{
    struct node *t;
    char x = -1;
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

char* convertINToPost(char*infix)
{
    int i=0,j=0;
    char *postfix;
    postfix = new char[strlen(infix)+2];

    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if(pre(infix[i])> pre(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while(top!=NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    return postfix;

}


int main()
{
    char*infix = "a+b*c-d/e";
    push('#');

    char* postfix = convertINToPost(infix);
    cout<<postfix<<endl;
    return 0;
}