#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int SubarraySumEqualToK(vector<int> &arr, int n, int k)
{
    int total = 0;
    unordered_map<int, int> m;
    int prefixSum = 0;
    m[0] = 1;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        cout << prefixSum << " ";
        if (m.count(prefixSum - k))
        {
            total += m[prefixSum - k];
            m[prefixSum]++;
        }
        else
        {
            m[prefixSum]++;
        }
    }
    cout << endl;
    return total;
}
int main()
{

    vector<int> arr = {3, 4, 5, 3, -6, 4, -2, 12};
    int n = arr.size();
    int k = 8;
    cout << SubarraySumEqualToK(arr, n, k);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    return 0;
}