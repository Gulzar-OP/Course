#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int climbR(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return climbR(n - 1) + climbR(n - 2);
}

// Memoization DP
int climbM(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = climbM(n - 1, dp) + climbM(n - 2, dp);
     return dp[n];x
}

int main()
{

    int n = 4;
    // cout << climbR(n);

    vector<int> dp(n + 1, -1);
    cout << climbM(n, dp) << endl;
    return 0;
}