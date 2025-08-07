#include <iostream>
using namespace std;

int hashFunction(int key, int size)
{
    return key % size;
}

void insert(int hashTable[], int size, int key)
{
    int index = hashFunction(key, size);
    int i = 1;
    while (hashTable[index] != -1)
    {
        index = (index + i * i) % size; // quadratic probing
        i++;
    }
    hashTable[index] = key;
}

int main()
{
    int size = 10;
    int hashTable[10];
    fill_n(hashTable, size, -1);

    int arr[] = {23, 43, 13, 27};
    for (int key : arr)
        insert(hashTable, size, key);

    cout << "Hash Table: ";
    for (int i = 0; i < size; i++)
        cout << hashTable[i] << " ";
}
