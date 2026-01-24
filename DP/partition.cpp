#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int getMinDiff(vector<int> num)
{
    int n = num.size();
    int totalSum = 0;
    for (int i = 0; i < num.size(); i++)
    {
        totalSum += num[i];
    }
    int w = totalSum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (num[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - num[i - 1]] + num[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int grp1 = dp[n][w];
    int grp2 = totalSum - grp1;
    int minDiff = abs(grp1 - grp2);
    return minDiff;
}

int main()
{
    vector<int> num = {1, 6, 11, 5};
    cout << "Minimum Difference: " << getMinDiff(num) << endl;
    return 0;
}