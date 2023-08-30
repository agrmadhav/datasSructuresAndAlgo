#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void traverse(Node* head){
    Node* p = head;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}

Node* reverse(Node* head,int k){
    if(head == NULL){
        return NULL;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    Node* temp = head;
    int i=0;
    while(temp != NULL && i<k){
        temp = temp->next;
        i++;
    }
    if(i<k){
        return head;
    }

    int count =0;
    while(curr != NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(curr != NULL){
        head->next = reverse(curr,k);
    }
    return prev;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int k=2;
    head = reverse(head,k);
    traverse(head);
    return 0;
}