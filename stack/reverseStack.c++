#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int>& s) {
    if (s.empty()) return;

    int top = s.top();
    s.pop();
    reverseStack(s);
    
    stack<int> temp;
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    
    s.push(top);
    
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Original Stack: ";
    printStack(s);

    reverseStack(s);

    cout << "Reversed Stack: ";
    printStack(s);

    return 0;
}