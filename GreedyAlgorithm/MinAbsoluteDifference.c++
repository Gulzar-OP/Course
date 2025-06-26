#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    vector<int> A = {4,1,8,7};
    vector<int> B = {2,3,6,5};

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    // chota chota se minus hoga
    // bada bada se 
    // tb minimum absolute difference milage

    int absDiff=0;
    for(int i=0;i<A.size();i++){
        absDiff += abs(A[i] - B[i]);
    }
    cout<<"Min Absolute Diff: "<<absDiff<<endl;

    return 0;
}