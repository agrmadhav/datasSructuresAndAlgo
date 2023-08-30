#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
    void insertAtTail(Node* &head,Node* &tail,int d){
        Node* newnode = new Node(d);
        if(head ==NULL){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }
public:
    // step 1 create a clone list
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp = temp->next;
        }
    // step 2 clonenodes add krne hai
    Node* orignalNode = head;
    Node* cloneNode = cloneHead;

    while(orignalNode != NULL && cloneNode != NULL){
        Node* next = orignalNode->next;
        orignalNode->next = cloneNode;
        orignalNode = next;

        next = cloneNode->next;
        cloneNode->next = orignalNode;
        cloneNode = next;
    }

    // step 3 random pointer copy
    temp = head;

    while(temp != NULL){
        if(temp->next != NULL){
            temp->next->random = temp->random? temp->random->next:temp->random; 
        }
        temp = temp->next->next;
    }

    // step 4 revert krne hai step 2 ko
    orignalNode = head;
    cloneNode = cloneHead;

    while(orignalNode != NULL && cloneNode != NULL){
        orignalNode->next = cloneNode->next;
        orignalNode = orignalNode->next;

        if(orignalNode != NULL){
        cloneNode->next = orignalNode->next;
        }
        cloneNode = cloneNode->next;
    }

    // step return ans
        return cloneHead;
    }
};




// solution using extra space

class mapSolution {
    void insertAtTail(Node* &head,Node* &tail,int d){
        Node* newnode = new Node(d);
        if(head ==NULL){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp = temp->next;
        }

        // create a map
        unordered_map<Node*, Node*> oldToNew;

        Node* orignalNode = head;
        Node* cloneNode = cloneHead;
        while(orignalNode != NULL){
            oldToNew[orignalNode] = cloneNode;
            orignalNode = orignalNode->next;
            cloneNode = cloneNode->next;
        }

        // copying the random pointer using mapping
        orignalNode = head;
        cloneNode = cloneHead;

        while(orignalNode != NULL){
            cloneNode->random = oldToNew[orignalNode->random];
            orignalNode = orignalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};

