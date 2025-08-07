#include <iostream>
using namespace std;

const int SIZE = 10;
int table[SIZE];

void basic_insert(int key)
{
    int index = key % SIZE;
    table[index] = key;
}
bool basic_search(int key)
{
    int index = key % SIZE;
    return table[index] == key;
}

void basic_delete(int key)
{
    int index = key % SIZE;
    if (table[index] == key)
        table[index] = -1;
}
int main()
{
    int arr[] = {15, 22, 67, 24, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int key : arr)
    {
        basic_insert(key);
    }

    cout << "Hash Table: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << table[i] << " ";
    }

    return 0;
}
