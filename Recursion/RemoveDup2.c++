#include<iostream>
using namespace std;

void Dup(string str, string ans, int map[26]){
    if(str.size()==0){
        cout<<"ans : "<<ans<<endl;
        return ;
    }
    int n=str.size();
    char back=str[n-1];
    
    int mapIdx=(int)(str[n-1]-'a');
    str=str.substr(0,n-1);

    if(map[mapIdx]==true){
        Dup(str,ans,map);
    }
    else{
        map[mapIdx] = true;
        Dup(str,back+ans,map);
    }

}

int main(){
    string str ="apnanaCollege";
    string ans = " ";
    int map[26]={false};
    Dup(str,ans,map);
    return 0;
}