#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val); // fixed
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val); // fixed
    }
    return root;
}

Node *BuildBst(int arr[], int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

Node *getInorderSuccessor(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *DeleteNode(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (val < root->data)
    {
        root->left = DeleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = DeleteNode(root->right, val);
    }
    else
    {
        // root == val
        // case:1 -> 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // case:2 -> 1 child
        if (root->left == NULL || root->right == NULL)
        {
            return root->left == NULL ? root->right : root->left;
        }
        // case:3 -> 2 child
        Node *IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = DeleteNode(root->right, IS->data);

        return root;
    }
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void range(Node *root, int start, int end)
{
    if (!root)
        return;

    if (start <= root->data && root->data <= end)
    {
        range(root->left, start, end);
        cout << root->data << " ";

        range(root->right, start, end);
    }
    else if (root->data < start)
    {
        range(root->right, start, end);
    }
    else
    {
        range(root->left, start, end);
    }
}

int main()
{
    int arr[6] = {5, 1, 3, 4, 2, 7};
    Node *root = BuildBst(arr, 6);
    inorder(root);

    cout << endl;
    DeleteNode(root, 4);
    inorder(root);
    cout << endl;

    range(root, 2, 5);

    return 0;
}