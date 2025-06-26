#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void dis(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<< " ";
        s.pop();
    }
}

void reversal(queue<int>q){
    stack<int>s;
    while(!q.empty()){
        s.push(q.front());

        q.pop();
    }
    dis(s);
}

int main(){
    queue<int>q;
    for(int i=0;i<5;i++){
        q.push(i);
    }

    reversal(q);
    return 0;
}