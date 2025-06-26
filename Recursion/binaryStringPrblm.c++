#include<iostream>
using namespace std;

void BinStr(int n,int lastPlace , string ans){
    if (n==0){
        cout<<ans<<endl;
        return; 
    }
    if(lastPlace !=1){
        BinStr(n-1,0,ans+'0');
        BinStr(n-1,1,ans+'1');
    }else{
        BinStr(n-1,0,ans+'0');
    }
}
int main(){
    string ans=" ";
    int n=3;
    BinStr(n,0,ans);
    // cout<<ans;

    return 0;
}