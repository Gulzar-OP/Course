#include <iostream>
using namespace std;

// Recursive function to find nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) return 0;        // Base case
    if (n == 1) return 1;        // Base case
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci series up to " << n << " terms:\n";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}
