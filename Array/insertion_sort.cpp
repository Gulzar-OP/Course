#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, j, num;
    for (int i = 1; i < n; i++)
    {
        num = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > num)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = num;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {11, 4, 34, 12, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
}