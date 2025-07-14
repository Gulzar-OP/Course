#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{

    priority_queue<int> pq;

    pq.push(5);
    pq.push(10);
    pq.push(15);
    pq.push(20);
    pq.push(25);

    // cout << pq.top() << endl;
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // reverse (minHeap)
    priority_queue<int, vector<int>, greater<int>> gpq;

    gpq.push(5);
    gpq.push(10);
    gpq.push(15);
    gpq.push(20);
    gpq.push(25);

    // cout << pq.top() << endl;
    while (!gpq.empty())
    {
        cout << gpq.top() << " ";
        gpq.pop();
    }
    return 0;
}