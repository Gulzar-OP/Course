#include <iostream>
using namespace std;

int hash1(int key, int size)
{
    return key % size;
}

int hash2(int key)
{
    return 7 - (key % 7); // should be relatively prime to table size
}

void insert(int hashTable[], int size, int key)
{
    int index = hash1(key, size);
    int step = hash2(key);
    while (hashTable[index] != -1)
    {
        index = (index + step) % size; // double hashing
    }
    hashTable[index] = key;
}

int main()
{
    int size = 10;
    int hashTable[10];
    fill_n(hashTable, size, -1);

    int arr[] = {10, 22, 31, 4, 15};
    for (int key : arr)
        insert(hashTable, size, key);

    cout << "Hash Table: ";
    for (int i = 0; i < size; i++)
        cout << hashTable[i] << " ";
}
