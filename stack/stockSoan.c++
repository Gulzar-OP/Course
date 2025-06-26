#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void stockSpan(vector<int>& stock, vector<int>& span) {
    stack<int> s;
    s.push(0); // Push index of the first element
    span[0] = 1; // Span for the first element is always 1

    for (int i = 1; i < stock.size(); i++) {
        int currPrices = stock[i];
        while (!s.empty() && stock[s.top()] <= currPrices) {
            s.pop();
        }
        if (s.empty()) {
            span[i] = i + 1; // All previous elements are smaller
        } else {
            int preHigherIndex = s.top();
            span[i] = i - preHigherIndex; // Current index - index of last greater element
        }
        s.push(i); // Push current index onto the stack
    }
}

int main(){
    vector<int> stock = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span(stock.size());
    stockSpan(stock, span);
    cout << "Stock Prices: ";
    for (int price : stock) {
        cout << price << " ";
    }
    cout << "\nStock Spans: ";
    for (int s : span) {
        cout << s << " ";
    }
    return 0;
}