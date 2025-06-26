#include<iostream>
using namespace std;

class Queue{
    int * arr;

    int capacity;
    int currSize;

    int f, r;
    public:
    Queue(int size){
        capacity=size;
        arr = new int[capacity];
        currSize=0;
        f=0;
        r=-1;

    }
    void push (int data){
        if(currSize == capacity){
            cout<<"Queue is full"<<endl;
            return ;
        }
        r=(r+1)%capacity;
        arr[r] = data;
        currSize ++;
    }
    void pop(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return ;
        }
        f = (f+1) % capacity;
        currSize --;
    }
    int front(){
        if(empty()){
            cout<<"Queue is empty";
            return -1;
        }
        return arr[f];
    }   
    bool empty(){
        return currSize==0;
    }
    void display(){
        for(int i =0; i<currSize;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main (){
    Queue q(4);

    q.push(10);
    q.push(20);
    q.push(40);
    q.push(30);
    q.push(10);
    q.display();
    q.pop();
    q.push(70);
    q.display();
    return 0;
}