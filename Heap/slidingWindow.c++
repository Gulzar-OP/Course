#include <iostream>
#include <queue>
using namespace std;

void SlidingWindowMax(vector<int> arr, intk)
{
    priority_queue<pair<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(make_pair(arr[i], i));
    }
    cout << "Output " << pq.top().first << " ";
    for (int i = k; i < arr.size(); i++)
    {
        while (!pq.empty() && pq.top().second <= (i - k))
        {
            pq.pop();
        }
        pq.push(make_pair(arr[i], i));
        cout << pq.top().first << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    SlidingWindowMax(arr, k);
    return 0;
}