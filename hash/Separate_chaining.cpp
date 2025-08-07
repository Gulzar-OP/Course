#include <iostream>
#include <list>
using namespace std;

class HashTable
{
    int size;
    list<int> *table;

public:
    HashTable(int size)
    {
        this->size = size;
        table = new list<int>[size];
    }

    void insert(int key)
    {
        int index = key % size;
        table[index].push_back(key);
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << ": ";
            for (int key : table[i])
                cout << key << " -> ";
            cout << "NULL\n";
        }
    }
};

int main()
{
    HashTable ht(10);
    int arr[] = {15, 11, 27, 8, 12};
    for (int key : arr)
        ht.insert(key);

    ht.display();
}
