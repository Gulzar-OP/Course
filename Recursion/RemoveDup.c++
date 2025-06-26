#include<iostream>
using namespace std;

void Dup(string str, string ans,int i, int map[26]){
    if(i==str.size()){
        cout<<"ans : "<<ans<<endl;
        return ;
    }
    
    char ch=str[i];
    int mapIdx=(int)(ch-'a');

    if(map[mapIdx]==true){
        Dup(str,ans,i+1,map);
    }
    else{
        map[mapIdx] = true;
        Dup(str,ans+str[i],i+1,map);
    }

}

int main(){
    string str ="Good";
    string ans = " ";
    int map[26]={false};
    Dup(str,ans,0,map);
    return 0;
}