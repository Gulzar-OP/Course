#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
    public:
    string key;
    int val;

    Node* next;
    Node(string key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
    }
};
class HashTable{
    int totalSize;
    int currSize;
    Node** table;
    int hashfunction(string key){
        int idx=0;
        for(int i=0;i<key.size();i++){
            idx=idx+(key[i]*key[i])%totalSize;
        }
        return idx;

    }
    public:
    HashTable(int size){
        totalSize = size;
        currSize=0;

        table=new Node*[totalSize];

        for(int i=0;i<totalSize;i++){
            table[i] = NULL;
        }
    }
    void insert(string key,val){
        int idx = hashfunction(key);
        Node* newNode=new Node(key,val);

        Node* head=table[idx];
        newNode->next=head;
        head=newNode;

        currSize++; 
    }
    void remove(string key){

    }
    int search(string key){

    }
};

int main(){
    HashTable ht;

    return 0;
}