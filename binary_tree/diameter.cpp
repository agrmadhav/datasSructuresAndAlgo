// longest path bw any two nodes also known as width or longest path bw two end nodes

#include <iostream>
#include <utility>
using namespace std;

// approach ans is in leftsubtree or in rightsubtree ya dono ko milakr
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    int max(int a, int b)
    {
        if (a > b)
            return a;
        else
            return b;
    }
    int height(struct Node *node)
    {
        // base case
        if (node == NULL)
        {
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
    }

    // int diameter(struct Node*node){
    //     //base case
    //     if(node == NULL){
    //         return 0;
    //     }
    //     int d1 = diameter(node->left);
    //     int d2 = diameter(node->right);
    //     int d3 = height(node->left) + height(node->right)+1;

    //     int res = max(d3,max(d1,d2));
    //     return res;
    // time complexity O(n^2)
    // }

    pair<int, int> diameterfast(Node *node)
    {
        // base cse
        if (node == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = diameterfast(node->left);
        pair<int, int> right = diameterfast(node->right);

        int d1 = left.first;
        int d2 = right.first;
        int d3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(d1, max(d2, d3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int diameter(Node *root)
    {
        return diameterfast(root).first;
    }
    // time complexity O(n)



// best solution
//     class Solution1 {
//     private:
//     int height(TreeNode* root,int& diameter){
//         if(root == NULL){
//             return 0;
//         }
//         int lh = height(root->left,diameter);
//         int rh = height(root->right,diameter);
//         diameter = max(diameter,lh+rh);
//         return 1+ max(lh,rh);
//     }
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         int diameter = 0;
//         height(root,diameter);
//         return diameter;
//     }
// };
};
