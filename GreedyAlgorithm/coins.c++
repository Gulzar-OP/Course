#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void notes(int v, vector<int> N){
    int n = N.size();
    int note =0;

    for(int i = 0; i < n; i++){
        if(v >= N[i]){
            int count = v / N[i]; 
            note++;       // How many notes of this denomination
            v = v % N[i];                // Remaining value
            cout << N[i] << " x " << count << endl;
        }
        
    }
    cout<<"Total Number of Notes: "<<note;
}

int main(){
    vector<int> N = {100, 50, 20, 10, 5, 2, 1};
    int v = 57;

    notes(v, N);
    return 0;
}
