#include<iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;  //pointer to array storing node type values
};

void create(struct Queue *q,int size)
{
    q->size = size;
    q->front = q->rear =0;
    // q->Q = (struct Node **)malloc(q->size*sizeof(struct Node*));
    q->Q = new Node*[size];
}

void enqueue(struct Queue *q,struct Node*x)
{
    if((q->rear+1)%q->size == q->front)
    cout<<"queue is full";

    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}


struct Node*dequeue(struct Queue*q)
{
    struct Node*x = NULL;

    if(q->front == q->rear)
      cout<<"queue is empty";

    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;  
}

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}

struct Node *root = NULL;

void TreeCreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);

    cout<<"enter root value"<<endl;
    cin>>x;
    root = new Node;
    root->data= x;
    root->lchild = root->rchild =0;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);

        cout<<"enter left child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }

        cout<<"enter rigth child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}

void PreOrder(struct Node*p)
{
    if(p)
    {
        cout<<p->data<<" ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}


void InOrder(struct Node*p)
{
    if(p)
    {
        InOrder(p->lchild);
        cout<<p->data<<" ";
        InOrder(p->rchild);
    }
}

void PostOrder(struct Node*p)
{
    if(p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout<<p->data<<" ";
    }
}


struct stack
{
    int size;
    int top;
    struct Node **S;
};

void Stackcreate(struct stack *st,int size)
{
    st->size = size;
    st->top = -1;
    st->S = new Node*[st->size];
}

// void display(struct stack st)
// {
//     for(int i= st.top;i>=0;i--)
//     {
//         cout<<st.S[i]<<endl;
//     }
// }

void push(struct stack* st,struct Node *x)
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

struct Node *pop(struct stack *st)
{
    struct Node *x = NULL;
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

// int peek(struct stack st,int pos)
// {
//     int x =-1;

//     if(st.top-pos+1<0)
//     {
//         cout<<"invalid index"<<endl;
//     }
//     else
//     {
//         x = st.S[st.top-pos+1];
//     }
//     return x;
// }

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


void IPreOrder(struct Node*p)
{
    struct stack stk;
    Stackcreate(&stk,100);

    while(p!=NULL || !isStackEmpty(stk))
    {
        if(p!=NULL)
        {
            cout<<p->data<<" ";
            push(&stk,p);
            p= p->lchild;
        }

        else
        {
            p = pop(&stk);
            p= p->rchild;
        }
    }
}


void IInOrder(struct Node*p)
{
    struct stack stk;
    Stackcreate(&stk,100);

    while(p!=NULL || !isStackEmpty(stk))
    {
        if(p!=NULL)
        {
            push(&stk,p);
            p= p->lchild;
        }

        else
        {
            p = pop(&stk);
            cout<<p->data<<" ";
            p= p->rchild;
        }
    }
}

// void IPostOrder(struct Node*p)
// {
//     struct stack stk;
//     Stackcreate(&stk,100);
//     long int temp;

//     while(p!=NULL || !isStackEmpty(stk))
//     {
//         if(p!=NULL)
//         {
//             push(&stk,(long int)p);
//             p= p->lchild;
//         }

//         else
//         {
//             temp = pop(&stk);
//             if(temp>0)
//             {
//                 push(&stk ,temp);
//                 p = ((Node*)temp)->rchild;
//             }
//             else
//             {
//                 cout<<((Node*)temp)->data;
//                 p = NULL;
//             }
//         }
//     }
// }

void LevelOrder(struct Node*root)
{
    struct Queue q;
    create(&q,100);

    cout<<root->data<<" ";
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        root = dequeue(&q);
        if(root->lchild)
        {
            cout<<root->lchild->data<<" ";
            enqueue(&q,root->lchild);
        }
        if(root->rchild)
        {
            cout<<root->rchild->data<<" ";
            enqueue(&q,root->rchild);
        }
    }
}



int main()
{
    TreeCreate();
    PreOrder(root);
    cout<<endl;

    InOrder(root);    
    cout<<endl;
    PostOrder(root);    


    return 0;
}