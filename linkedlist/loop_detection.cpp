#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node{
    int data;
    struct node*next;
}*head1 = NULL;

void traverse(struct node*p){
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

struct node* detectloop(struct node*head){
    if(head == NULL){
        return NULL;
    }
    struct node*slow = head;
    struct node*fast = head;

    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

struct node* startingnode(struct node*head){
    if(head == NULL){
        return NULL;
    }

    struct node*intersection = detectloop(head);

    struct node*slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

struct node*removeloop(struct node *head){
    if(head == NULL){
        return NULL;
    }

    struct node*startofloop = startingnode(head);

    struct node * temp = startofloop;

    while(temp->next != startofloop){
        temp = temp->next;
    }

    temp->next = NULL;

    return head;
}

int main(){
    struct node *head1 = (struct node*)malloc(sizeof(struct node));
    struct node *second1 = (struct node*)malloc(sizeof(struct node));
    struct node *third1 = (struct node*)malloc(sizeof(struct node));
    struct node *fourth1 = (struct node*)malloc(sizeof(struct node));
    struct node *fifth1 = (struct node*)malloc(sizeof(struct node));
    struct node *sixth1 = (struct node*)malloc(sizeof(struct node));
    head1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    fifth1->next = sixth1;
    sixth1->next = third1;

    head1->data = 10;
    second1->data = 20;
    third1->data = 30;
    fourth1->data = 40;
    fifth1->data = 50;
    sixth1->data = 60;

    // traverse(head1);
    struct node *loop = detectloop(head1);


    if(loop !=NULL){
        cout<<"cycle is present at "<<endl;

        cout<<"loop starts at "<<startingnode(head1)->data<<endl;
    }

    else{
        cout<<"cycle is not present"<<endl;
    }

    head1 = removeloop(head1);
    traverse(head1);


    struct node *loop2 = detectloop(head1);


    if(loop2 !=NULL){
        cout<<"cycle is present at "<<endl;

        cout<<"loop starts at "<<startingnode(head1)->data<<endl;
    }

    else{
        cout<<"cycle is not present"<<endl;
    }


    return 0;
}