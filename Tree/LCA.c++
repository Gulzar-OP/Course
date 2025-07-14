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

// bool rootToNodePath(Node *root,int n,vector<int> &path){
//     if(root==NULL){
//         return false;
//     }
//     path.push_back(root->data);
//     if(root->data == n){
//         return true;
//     }
//     int isLeft = rootToNodePath(root->left,n,path);
//     int isRight = rootToNodePath(root->right,n,path);

//     if(! isLeft || ! isRight){
//         return true;
//     }
//     path.pop_back();
// }
// int LCA(Node *root,int n1,int n2){
//     vector<int>path1;
//     vector<int>path2;

//     rootToNodePath(root,n1,path1);
//     rootToNodePath(root,n2,path2);

//     int lca = -1;
//     for(int i=0, j=0; i<path1.size() && j<path2.size(); i++,j++){
//         if(path1[i] != path2[i]){
//             return lca;
//         }
//         lca = path1[i];
//     }
//     return lca;

// }


Node* LCA(Node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data == n1 || root->data == n2) return root;

    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

    if (leftLCA && rightLCA) return root;  // n1 & n2 found in different subtrees

    return leftLCA ? leftLCA : rightLCA;  // n1 & n2 in same subtree or not found
}

int main() {
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int idx = 0;
    Node *root = buildtree(arr, idx);

    int n1 = 4, n2 = 5;
    Node *lca = LCA(root, n1, n2);

    if (lca)
        cout << "LCA: " << lca->data << endl;
    else
        cout << "LCA not found!" << endl;

    return 0;
}
