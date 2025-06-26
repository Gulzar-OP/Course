#include <iostream>
using namespace std;

// Function to print the array
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Recursive function to change array
void changeArr(int arr[], int n, int i) {
    if (i == n) {
        printArr(arr, n);  // Print when recursion reaches the end
        return;
    }

    arr[i] = i + 1;              // Assign i+1 to current index
    changeArr(arr, n, i + 1);    // Recursive call
    arr[i] -= 2;                 // Subtract 2 during backtracking
}

// Main function
int main() {
    int arr[5] = {0};  // Initialize array with 0s
    int n = 5;

    changeArr(arr, n, 0);  // First print inside recursion
    printArr(arr, n);      // Final print after backtracking

    return 0;
}
