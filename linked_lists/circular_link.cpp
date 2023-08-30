#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next; 
}*head = NULL;

void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    head = new node;
    head->data = A[0];
    head->next = head;
    last = head;

    for(i=1;i<n;i++)
    {
        t = new node;
        t->data=A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

int length(struct node*p)
{
    int len =0;
    do
    {
        len++;
        p=p->next;
    } while (p!=head);

    return len;
    
}

void display(struct node*h)
{
    do
    {
        cout<<h->data<<" ";
        h= h->next;
    } while (h!= head);
    cout<<endl;
}
void rec_display(struct node*h)
{
    static int flag =0;
    if(h!=head || flag ==0)
    {
        flag =1;
        cout<< h->data;
        rec_display(h->next);
    }
    flag =0;
}

void insert(struct node *p,int index,int x)
{
    struct node*t;
    int i;
    if(index<0||index>length(head))
    {
        return;
    }

    if(index ==0)
    {
        t = new node;
        t->data = x;
        if(head == NULL)
        {
            head =t;
            head ->next = head;
        }
        else
        {
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next =t;
            t->next =head;
            head =t;
        }
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            p= p->next;
        }
        t = new node;
        t->data = x;
        t->next = p->next;
        p->next =t;
    }
}
int Delete(struct node*p,int index)
{
    struct node*q;
    int i;
    int x;
    if(index<0 || index >length(head))
    {
        return -1;
    }
    if(index ==1)
    {
        while(p->next !=head)
        {
            p=p->next;
        }
        x = head->data;
        if(head == p)
        {
            delete(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete(head);
            head = p->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++)
        {
            p=p->next;
        }
        q= p->next;
        p->next = q->next;
        x= q->data;
        delete(q);
    }
    return x;
}
int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);
    Delete(head,4);
    display(head);
    return 0;
}