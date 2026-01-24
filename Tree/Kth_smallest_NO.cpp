#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Build tree in preorder
Node *buildtree(const vector<int> &arr, int &idx)
{
    if (idx >= arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }

    Node *root = new Node(arr[idx++]);
    root->left = buildtree(arr, idx);
    root->right = buildtree(arr, idx);
    return root;
}

// Collect all nodes
void collect(Node *root, vector<int> &vals)
{
    if (!root)
        return;
    collect(root->left, vals);
    vals.push_back(root->data);
    collect(root->right, vals);
}

// Kth smallest for generic tree
int kth_smallest(Node *root, int k)
{
    vector<int> vals;
    collect(root, vals);
    sort(vals.begin(), vals.end()); // sort for kth smallest
    return vals[k - 1];             // kth smallest
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int idx = 0;
    Node *root = buildtree(arr, idx);
    cout << kth_smallest(root, 2) << endl; // 2
    return 0;
}
