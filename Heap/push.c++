#include <iostream>
#include <vector>

using namespace std;

class Heap
{
    vector<int> vec;

    // Helper function to restore heap property from index i downwards
    void heapify(int i)
    {
        int size = vec.size();
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Compare left child
        if (left < size && vec[left] > vec[largest])
            largest = left;

        // Compare right child
        if (right < size && vec[right] > vec[largest])
            largest = right;

        // If largest is not current node, swap and recurse
        if (largest != i)
        {
            swap(vec[i], vec[largest]);
            heapify(largest);
        }
    }

public:
    // Insert a new value into the heap
    void push(int val)
    {
        vec.push_back(val);
        int x = vec.size() - 1;
        int parI = (x - 1) / 2;

        // Bubble up
        while (x > 0 && vec[x] > vec[parI])
        {
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x - 1) / 2;
        }
    }

    // Remove the maximum element (root of the heap)
    void pop()
    {
        if (vec.empty())
            return;

        // Replace root with last element
        vec[0] = vec.back();
        vec.pop_back();

        // Restore heap property
        heapify(0);
    }

    // Return the maximum element at the root
    int top()
    {
        if (vec.empty())
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return vec[0];
    }

    bool empty()
    {
        return vec.empty();
    }

    // Utility: Print heap as array (for debugging)
    void print()
    {
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{
    Heap heap;
    heap.push(5);
    heap.push(12);
    heap.push(2);
    heap.push(9);

    cout << "Initial heap top: " << heap.top() << endl; // 12
    heap.print();                                       // print heap array

    heap.pop();
    cout << "After pop, heap top: " << heap.top() << endl; // should be 9
    heap.print();

    heap.pop();
    cout << "After another pop, heap top: " << heap.top() << endl; // should be 5 or 2
    heap.print();

    return 0;
}
