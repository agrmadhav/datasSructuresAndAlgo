// longest path bw leaf node and root node

#include <bits/stdc++.h> // includes all standard libararay

// approach is recursion

// ans = max(height of leftsubtree , height of right subtree)+1 where 1 is of root node

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
    // function to find height of tree
    int height(struct Node *node)
    {
        // base case
        if (node == NULL)
        {
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);

        int ans = max(left, right) + 1;
        return ans;
    }
};
// time complexity O(n)
// space complexity O(logn) O(n) in skewed trees due to recursion
