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

Node * BSTfromSorted(int Sarr[],)

int main()
{
    int arr[6] = {5, 1, 3, 4, 2, 7};
    vector<int>Sarr;
    for(int i =0;i<6;i++){
        if(arr[i]<arr[i+1]){
            Sarr.push_back(arr[i]);
        }
    }
    Node *root = BuildBst(arr, 6);
    inorder(root);
    cout << endl;

    return 0;
}
