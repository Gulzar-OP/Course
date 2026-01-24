#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
long long int findZeroSum(vector<long long int> &arr, int n)
{
    long long int total = 0;
    unordered_map<long long int, long long int> m;
    long long int prefixSum = 0;
    m[0] = 1;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (m.count(prefixSum))
        {
            total += m[prefixSum];
            m[prefixSum]++;
        }
        else
        {
            m[prefixSum] = 1;
        }
    }
    return total;
}
int main()
{

    vector<long long int> arr = {6, 4, -5, 1, 8, 3, 2, -10, -4, 0, 4, -9};
    int n = arr.size();
    cout << findZeroSum(arr, n);
    cout << endl;
    return 0;
}