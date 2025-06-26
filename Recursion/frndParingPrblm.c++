#include<iostream>
using namespace std;

int frndParing(int n){
    if(n==1 || n==2){
        return n;
    }
    return frndParing(n-1) + (n-1)*frndParing(n-2);
}

int main(){
    cout << frndParing(3)<<endl;
    return 0;
}