#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fib(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci series up to " << n << " terms:\n";
    
    vector<int> dp(n + 1, -1);
    cout<<fib(n, dp) << endl;

    return 0;
}