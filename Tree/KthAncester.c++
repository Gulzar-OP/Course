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


int KthAncester(Node* root, int node,int k) {
    if (!root)
     return -1;

    if (root->data == node)
     return 0;

    int leftDist = KthAncester(root->left, node,k);
    int rightDist = KthAncester(root->right, node,k);

    if (leftDist ==-1 && rightDist==-1) 
    return -1; 

    int validVal = leftDist==-1 ? rightDist:leftDist;
    if(validVal +1==k){
        cout<<"Kth Ancestor: "<<root->data<<endl;
    }

    return validVal +1;
}

int main() {
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int idx = 0;
    Node *root = buildtree(arr, idx);

    int node=5,k=2;
    KthAncester(root,node,k);


    return 0;
}
