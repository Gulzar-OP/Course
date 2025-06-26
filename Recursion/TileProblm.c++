#include<iostream>
using namespace std;

int TP(int n){
    // base case
    if(n==0||n==1){
        return 1;
    }
    // vertical
    int ans1 = TP(n-1);
    // horizontal
    int ans2 = TP(n-2);

    return ans1+ans2;
    
}

int main(){
    int n=5;
    cout<<TP(n);
    return 0;
}