#include<iostream>
#include<vector>
using namespace std;

void printSubset(vector<int>& arr, vector<int>& ans, int i) {
    if(i == arr.size()) {
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }
    
    // Include the current element in the subset
    ans.push_back(arr[i]);
    printSubset(arr, ans, i + 1);
    
    // Exclude the current element from the subset
    ans.pop_back();
    printSubset(arr, ans, i + 1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ans;
    printSubset(arr, ans, 0);

    return 0;
}
