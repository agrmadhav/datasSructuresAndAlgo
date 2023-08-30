#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->data = x;
        this->left = this->right = NULL;
    }
};

class Solution
{
public:
    // function to store the zigzag traversal
    vector<int> zigzagtraversal(Node *root)
    {
        vector<int> res;
        if (root == NULL)
        {
            return res;
        }

        queue<Node *> q;
        q.push(root);
        bool lefttoright = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);

            // level process
            for (int i = 0; i < size; i++)
            {
                Node *frontnode = q.front();
                q.pop();

                // normal insertion or recursive insertion
                int index = lefttoright ? i : size - i - 1;
                ans[index] = frontnode->data;

                if (frontnode->left)
                {
                    q.push(frontnode->left);
                }

                if (frontnode->right)
                {
                    q.push(frontnode->right);
                }
            }
            // direction change
            lefttoright = !lefttoright;

            for (auto i : ans)
            {
                res.push_back(i);
            }
        }
    }
};

int main()
{
    return 0;
}