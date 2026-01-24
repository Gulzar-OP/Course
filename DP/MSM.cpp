#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int mcmrec(vector<int> arr, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost1 = mcmrec(arr, i, k);
        int cost2 = mcmrec(arr, k + 1, j);
        int cost = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, cost);
    }
    return ans;
    // time complexity: O(n^3)
}
int mcmMemoization(vector<int> arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost1 = mcmMemoization(arr, i, k, dp);
        int cost2 = mcmMemoization(arr, k + 1, j, dp);
        int cost = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, cost);
    }
    return dp[i][j] = ans;
    // time complexity: O(n^3)
}

int mcmTabulation(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost1 = dp[i][k];
                int cost2 = dp[k + 1][j];
                int cost = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n - 1];
//  time complexity: O(n^3)
}

int main()
{
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();
    // cout << "Minimum Cost of Matrix Multiplication: " << mcmrec(arr, 1, n - 1) << endl;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Minimum Cost of Matrix Multiplication with Memoization: " << mcmMemoization(arr, 1, n - 1, dp) << endl;
    return 0;
}