#include <iostream>
using namespace std;

int main()
{
    int bit[3] = {2,3,4};
    int result=0;
    for(int i=0;i<3;i++){
        result ^= bit[i];
    }
    cout << "Result: " << result << endl; // Output: 6
    return 0;
}
