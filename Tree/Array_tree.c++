#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node * left,*right;
    Node(int val){
        data = val;
        left=right=NULL;
    }
};
Node * buildtree(const vector<int>&arr,int & idx){
    if(idx >= arr.size() || arr[idx]==-1){
        idx++;
        return nullptr;
    }
    Node * root=new Node(arr[idx++]);
    root->left = buildtree(arr,idx);
    root->right= buildtree(arr,idx);
    return root;
}

void preorder(Node * root){
    if(root==NULL){
        return ;
    }

    // root
    cout<<root->data;
    // left
    preorder(root->left);
    // right
    preorder(root->right);
}


int main(){
    vector<int>arr={1,3,3,-1,-1,4,-1,-1,5,-1,6,-1,-1};
    int idx=0;
    Node *root=buildtree(arr,idx);
    preorder(root);
    return 0;
}