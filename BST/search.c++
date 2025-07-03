#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }
    if (val < root->data) {
        root->left = insert(root->left, val);    // fixed
    } else if (val > root->data) {
        root->right = insert(root->right, val);  // fixed
    }
    return root;
}

Node* BuildBst(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}
bool searchBst(Node *root,int tar){
    if(root==NULL){
        return false ;
    }

    if(tar == root->data){
        return true;
    }
    else if(tar < root->data){
        return searchBst(root->left,tar);
    }
    else if(tar > root->data){
        return searchBst(root->right,tar);
    }
    
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int arr[6] = {5, 1, 3, 4, 2, 7};
    Node* root = BuildBst(arr, 6);
    inorder(root);

    cout << endl;

    int g=searchBst(root,8);
    if(g){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found";
    }
    return 0;
}