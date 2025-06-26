#include<iostream>
using namespace std;

int partition(int arr[], int si, int en) {
    int pivot = arr[en];  // pivot is the last element
    int i = si - 1;

    for (int j = si; j < en; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot at correct position
    swap(arr[i + 1], arr[en]);
    return i + 1;  // return pivot index
}

void quickSort(int arr[], int si, int en) {
    if (si < en) {
        int pivotInd = partition(arr, si, en);
        quickSort(arr, si, pivotInd - 1);   // Left side
        quickSort(arr, pivotInd + 1, en);   // Right side
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}
