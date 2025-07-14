#include<iostream>
#include<vector>
#include<algorithm>
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
void KthHelper(Node * root,int k,int lvl){
    if(root==NULL){
        return;
    }

    if(lvl==k){
        cout<<root->data<<" ";
        return;
    }
    KthHelper(root->left,k,lvl+1);
    KthHelper(root->right,k,lvl+1);
}

void KthLevelTree(Node * root,int k){
    KthHelper(root,k,1);
    cout<<endl;

}

int main(){
    vector<int>arr={1,3,3,-1,-1,4,-1,-1,5,-1,6,-1,-1};
    int idx=0;
    Node *root=buildtree(arr,idx);
    KthLevelTree(root,2);
    return 0;
}