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

void searchBst(Node *root, int tar)
{
    if (root == NULL)
    {
        return;
    }
    bool m = false;

    if (tar == root->data)
    {
        cout << "Found";
        m = true;
    }
    else if (tar < root->data)
    {
        searchBst(root->left, tar);
    }
    else if (tar > root->data)
    {
        searchBst(root->right, tar);
    }

    else if (m == false)
    {
        cout << "Not Found";
    }
}
Node *BuildBstFromSorted(vector<int> Sarr, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    Node *curr = new Node(arr[mid]);

    curr->left = BuildBstFromSorted(Sarr, start, mid - 1);
    curr->right = BuildBstFromSorted(Sarr, mid + 1, end);

    return curr;
}
void getInorder(Node *root, vector<int> nodes)
{
    if (!root)
        return;

    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}
Node *balanceBST(Node *root)
{
    vector<int> nodes;
    getInorder(root, nodes);
    rooot = BuildBstFromSorted(nodes, 0, nodes.size() - 1);
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
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    int arr[6] = {5, 1, 3, 4, 2, 7};
    vector<int> Sarr = {1, 2, 3, 4, 5, 7};
    Node *root = BuildBst(arr[], 6);
    inorder(root);
    cout << endl;

    return 0;
}
