// 26/01/26
#include <iostream>
#include <vector>
#include <climits>
#include<unordered_set>
using namespace std;

// bruteforce Approach
// bool containsNearbyDuplicate(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             if (nums[i] == nums[j])
//             {
//                 if ((i - j) <= k)
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }

// sliding window Approach
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_set<int> window;
    for (int i = 0; i < n; i++)
    {
        if (window.count(nums[i]))
        {
            return true;
        }
        window.insert(nums[i]);

        if (window.size() > k)
        {
            window.erase(nums[i - k]);
        }
    }
    return false;
}
int main()
{
    vector<int> arr = {1, 2, 3, 1, 2, 3};
    int k = 2;
    cout<<containsNearbyDuplicate(arr, k);
    return 0;
}