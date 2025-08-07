#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsackRec(vector<int> val, vector<int> wt, int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];
    if (itemWt <= W)
    {
        // include
        int ans1 = knapsackRec(val, wt, W - itemWt, n - 1) + itemVal;

        // exclude
        int ans2 = knapsackRec(val, wt, W, n - 1);
        return max(ans1, ans2);
    }
    else
    {
        // exclude
        return knapsackRec(val, wt, W, n - 1);
    }
}

// Memoization DP
int knapsackMem(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>> &dp)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    int itemVal = val[n - 1];
    int itemWt = wt[n - 1];

    if (itemWt <= W)
    {
        int ans1 = knapsackMem(val, wt, W - itemWt, n - 1, dp) + itemVal;

        int ans2 = knapsackMem(val, wt, W, n - 1, dp);
        dp[n][W] = max(ans1, ans2);
    }
    else
    {
        dp[n][W] = knapsackMem(val, wt, W, n - 1, dp);
    }
    return dp[n][W];
}

// Tabulation DP
int knapsackTab(vector<int> val, vector<int> wt, int W, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            int itemVal = val[i - 1];
            int itemWt = wt[i - 1];

            if (itemWt <= j)
            {
                dp[i][j] = max(itemVal + dp[i - 1][j - itemWt], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int n = 5;
    int W = 7;
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};

    // cout << knapsackRec(val, wt, W, n) << endl;
    // Memoization
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    // cout << knapsackMem(val, wt, W, n, dp) << endl;

    // Tabulation
    cout << knapsackTab(val, wt, W, n) << endl;
    return 0;
}