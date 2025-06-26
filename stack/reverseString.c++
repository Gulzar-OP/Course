#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverseString(string str){
    string ans;
    stack<char> s;
    for(char c : str){
        s.push(c);
    }
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    return ans;
}
int main(){
    string str="Hello, World!";
    cout<< "Original String: " << str << endl;
    cout<< "Reversed String: "<<reverseString(str) << endl;
    return 0;
}

// TC O(n) where n is the length of the string
// SC O(n) for the stack used to store characters