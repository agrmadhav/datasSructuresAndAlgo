#include<iostream>
#include<stdlib.h>

using namespace std;

struct stack
{
    int size;
    int top;
    int *S;
};

void create(struct stack *st)
{
    cout<<"enter size of stack"<<endl;
    cin>>st->size;
    st->top = -1;
    st->S = new int[st->size];
}

void display(struct stack st)
{
    for(int i= st.top;i>=0;i--)
    {
        cout<<st.S[i]<<endl;
    }
}

void push(struct stack* st,int x)
{
    if(st->top == st->size -1)
    {
        cout<<"stack is full ,ie stack overflow"<<endl;
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }

}

int pop(struct stack *st)
{
    int x = -1;
    if(st->top == -1)
    {
        cout<<"stack is empty or stack underflow"<<endl;
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct stack st,int pos)
{
    int x =-1;

    if(st.top-pos+1<0)
    {
        cout<<"invalid index"<<endl;
    }
    else
    {
        x = st.S[st.top-pos+1];
    }
    return x;
}

int isStackFull(struct stack st)
{
    if(st.top == st.size-1)
    return 1;

    else
    return 0;
}

int isStackEmpty(struct stack st)
{
    if(st.top == -1)
    {
        return 1;
    }
    else
    return 0;
}

int main()
{
    struct stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);

    cout<<peek(st,2)<<endl;

    display(st);
    return 0;
}