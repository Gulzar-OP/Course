#include <iostream>
#include <vector>
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
void PrintPath(vector<int> path)
{
    cout << " path: ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

void pathHelper(Node *root, vector<int> &path)
{
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);

    if (root->left == NULL && root->right == NULL)
    {
        PrintPath(path);
        path.pop_back();
        return;
    }
    pathHelper(root->left, path);
    pathHelper(root->right, path);

    path.pop_back();
}
void rootToLeafPath(Node *root)
{
    vector<int> path;
    pathHelper(root, path);
}
int main()
{
    int arr[6] = {5, 1, 3, 4, 2, 7};
    Node *root = BuildBst(arr, 6);

    inorder(root);
    cout << endl;
    rootToLeafPath(root);

    return 0;
}