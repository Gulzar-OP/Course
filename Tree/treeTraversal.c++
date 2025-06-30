#include<iostream>
#include<vector>
#include<queue>
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
    cout<<root->data<<" ";
    // left
    preorder(root->left);
    // right
    preorder(root->right);
}
void inOrder(Node * root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node * root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node * root){
    if(root==NULL){
        return ;
    }
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left != nullptr){
            q.push(curr->left);
        }

        if(curr->right != nullptr){
            q.push(curr->right);
        }
    }

}
int height(Node * root){
    if(root==NULL){
        return 0;
    }
    int leftHT = height(root->left);
    int rightHT = height(root->right);
    int HT = max(leftHT,rightHT) + 1;

    return HT;
}

int main(){
    vector<int>arr={1,3,3,-1,-1,4,-1,-1,5,-1,6,-1,-1};
    int idx=0;
    Node *root=buildtree(arr,idx);
    // preorder(root);
    // inOrder(root);
    // postOrder(root);
    levelOrder(root);
    cout<<"\nHeight of Tree: "<<height(root);
    return 0;
}