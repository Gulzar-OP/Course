#include<iostream>
using namespace std;

void PrintSubset(string str,string subset){
    if(str.size()==0){
        cout<<subset<<"\n";
        return;
    }

    char ch=str[0];
    // yes
    PrintSubset(str.substr(1,str.size()-1),subset+ch); 

    // no
    PrintSubset(str.substr(1,str.size()-1),subset);
}

int main(){
    string str = "abc";
    string subset = "";
    PrintSubset(str,subset);
    return 0;
}