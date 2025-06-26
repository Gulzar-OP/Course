#include<iostream>
#include<queue>
#include<string>
using namespace std;

void NonRepeating(string ch){
    int frq[26] = {0};
    int n = ch.size();
    // cout<<n;
    queue<char>q;
    for(int i=0;i<n;i++){
        char c=ch[i]; 
        q.push(c);
        frq[c-'a']++;

        while (!q.empty()&&frq[q.front()-'a']>1)
        {
            q.pop();
        }
        if(q.empty()){
            cout<<"-1\n";
        }else{
            cout<<q.front()<<"\n";
        }

    }
}
// void display(string ch){
//     int n = ch.size();
//     for(int i=0;i<n;i++){
//         cout<<ch[i]<<"  ";
//     }
// }
int main(){
    string ch = "aabcb";
    NonRepeating(ch);
    // display(ch);
    return 0;
}