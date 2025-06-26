#include<iostream>
using namespace std;

bool checkSorted(int arr[], int n) {
    if (n == 1) {
        return true;
    }
    if (arr[n - 1] < arr[n - 2]) {
        return false;
    }
    return checkSorted(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (checkSorted(arr, n)) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is not sorted." << endl;
    }
    return 0;
}