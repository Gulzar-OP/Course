#include<iostream>
#include<map>

using namespace std;
int main(){
    map<int,int> myMap;
    myMap[1]=100;
    myMap[2]=200;
    myMap[3]=300;

    // purana value pr naya value overwrite kr dega
    myMap[1]=500;
    cout<<"value at key 1: "<<myMap[1]<<endl;
    for(auto it: myMap){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}