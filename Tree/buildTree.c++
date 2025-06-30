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
}
int main(){
    int x;
    queue<Node *>q;
    Node * root=new Npde(x);
    q.push(root);

    int first,second;

    // building tree
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        cout<<"Enter Left child: "<<temp->data<<" : ";
        cin>>first;
        if(first != -1){
            temp->left = new Node(first);
            q.push(temp->data);
        }
        cout<<"Enter the second : "<<temp->data<<":";
        cin = second;

        if(second != -1){
            temp->right = new Node(second);
            q.push(temp->right);
        }

    }

    return 0;
}