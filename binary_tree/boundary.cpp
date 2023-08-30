#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution{
    // left part exlcuding leaf Node
    // leaf node print kraoonga
    // right part excluding leaf node and we have to print it in reverse direction

    //left part
    void traverseleft(Node * root, vector<int> &ans){
        // base case
        if(root == NULL){
            return ;
        }
        if(root->left && root->right){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            traverseleft(root->left,ans);
        }
        else{
            traverseleft(root->right,ans);
        }
    }

    // leaf node
    void traverseleaf(Node*root,vector<int>&ans){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        traverseleaf(root->left ,ans);
        traverseleaf(root->right ,ans);
    }

    void traverseright(Node*root,vector<int>&ans){
        if(root== NULL){
            return;
        }
        if(root->left== NULL && root->right == NULL){
            return;
        }

        if(root->right){
            traverseright(root->right,ans);
        }
        else{
            traverseright(root->left,ans);
        }

        ans.push_back(root->data);
    }


    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if(root== NULL){
            return ans;
        }

        ans.push_back(root->data);

        traverseleft(root->left,ans);

        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);

        traverseright(root->right,ans);
    }


};