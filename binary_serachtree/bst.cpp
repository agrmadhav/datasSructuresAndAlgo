#include<iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;


void insert(int key)
{
    struct Node *t = root;
    struct Node *r,*p;

    if(root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root =p;
        return;
    }
    while(t!= NULL)
    {
        r = t;
        if(key <t->data)
           t = t->lchild;

        else if(key>t->data)
            t = t->rchild;  

        else
        return;     
    }
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;

        if(key <r->data) r->lchild =p;
        else r->rchild = p;
}

struct Node * search(int key)
{
    struct Node *t = root;

    while(t!=NULL)
    {
        if(key == t->data)
        {
            return t;
        }
        else if(key <t->data)
        {
            return t->lchild;
        }
        else
        {
            return t->rchild;
        }
    }
    return NULL;
}


// inorder traversal of bst result in sorted tree

int main()




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        // An empty tree is a BST of size 0.
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST.
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 
                            left.maxSize + right.maxSize + 1);
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    public:
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

{
    return 0;
}
