#include <iostream>
using namespace std;

bool isUgly(int n)
{
    // base cases
    if (n == 1)
        return true;
    if (n <= 0)
        return false;

    // recursive cases
    if (n % 2 == 0)
        return isUgly(n / 2);
    if (n % 3 == 0)
        return isUgly(n / 3);
    if (n % 5 == 0)
        return isUgly(n / 5);

    return false;
}

int main()
{
    int n = 5;
    cout << isUgly(n); // 1 means true, 0 means false
    return 0;
}
