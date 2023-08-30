#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d) // creating constructor
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildtree(node *root)
{
    cout << "enter the data for root node " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "enter the data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);

    cout << "enter the data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

void levelordertraversal1(node *root) // in single line
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data<<" ";
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

void levelordertraversal2(node *root) // creating it level wise
{
    queue<node*> q;
    q.push(root);
    q.push(NULL); // creating separator

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL); // queue still have some child nodes
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inordertraversal(node *root)
{

    if (root != NULL)
    {
        inordertraversal(root->left);
        cout << root->data << " ";
        inordertraversal(root->right);
    }
}

void preordertraversal(node *root)
{

    if (root != NULL)
    {
        cout << root->data << " ";
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}

void postordertraversal(node *root)
{
    if (root != NULL)
    {
        postordertraversal(root->left);
        postordertraversal(root->right);
        cout << root->data << " ";
    }
}

void buildFromLevelOrder(node *&root)
{
    queue<node *> q;

    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;

    // creating binary tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildtree(root);

    cout << "level order traversal" << endl;
    levelordertraversal2(root);
    // level order traversal

    cout << "inorder traversal" << endl;
    inordertraversal(root);
    cout << "preorder traversal" << endl;
    preordertraversal(root);
    cout << "postorder traversal" << endl;
    postordertraversal(root);

    return 0;
}