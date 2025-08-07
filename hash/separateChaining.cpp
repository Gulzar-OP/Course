#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
private:
    int size;
    vector<list<int>> table; // Vector of linked lists

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) {
        size = s;
        table.resize(size);
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key)
                return true;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key); // remove from linked list
    }

    void display() {
        cout << "\nHash Table (Separate Chaining):\n";
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            for (int val : table[i]) {
                cout << val << " -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht(5);

    ht.insert(10);
    ht.insert(15);
    ht.insert(20);
    ht.insert(25);
    ht.insert(7);

    ht.display();

    cout << "\nSearching 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    ht.remove(15);
    ht.display();

    return 0;
}


