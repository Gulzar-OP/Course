#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    // Push element onto stack
    void push(int x) {
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Removes the element on top of the stack
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q1.pop();
    }

    // Get the top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    // Check whether the stack is empty
    bool empty() {
        return q1.empty();
    }
};

//Example Usage
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << endl;
}
