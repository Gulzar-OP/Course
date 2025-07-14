#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // for std::find

using namespace std;

class Hashing
{
public:
    vector<list<int>> hashtable;
    int buckets;

    Hashing(int size)
    {
        buckets = size;
        hashtable.resize(size);
    }

    int hashFunction(int key)
    {
        return key % buckets; // division method
    }

    void add(int key)
    {
        int index = hashFunction(key);
        hashtable[index].push_back(key);
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        auto it = search(key); // get the iterator

        if (it != hashtable[index].end())
        {
            hashtable[index].erase(it); // erase using iterator
            cout << "Key removed!" << endl;
        }
        else
        {
            cout << "Key not found!" << endl;
        }
    }

    list<int>::iterator search(int key)
    {
        int index = hashFunction(key);
        return find(hashtable[index].begin(), hashtable[index].end(), key);
    }
};

int main()
{
    Hashing h(10); // 10 buckets
    h.add(5);
    h.add(15);
    h.add(25);
    h.remove(15);
    h.remove(100); // testing key not found

    return 0;
}
