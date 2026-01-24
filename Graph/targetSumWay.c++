#include <iostream>
#include <vector>
using namespace std;

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int countWay = 0;

    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += nums[j];
            }
            else
            {
                sum -= nums[j];
            }
        }
        if (sum == target)
        {
            countWay++;
        }
    }
    return countWay;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << findTargetSumWays(nums, target) << endl;
    return 0;
}
