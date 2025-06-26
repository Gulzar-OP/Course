#include <iostream>
using namespace std;

// Merges two sorted halves arr[l..mid] and arr[mid+1..r]
void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // Temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];  // j < n2

    int i = 0, j = 0, k = l;

    // Compare and merge back into arr[l..r]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy any remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

// Sorts arr[l..r] using merge()
void mergeSort(int arr[], int l, int r) {
    if (l >= r)  // base case: one element
        return;

    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);      // sort first half
    mergeSort(arr, mid + 1, r);  // sort second half
    merge(arr, l, mid, r);       // merge both halves
}

// Utility to print array
void PrintArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {6, 3, 2, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    PrintArr(arr, n);  // Output: 2 3 5 6 9

    return 0;
}
