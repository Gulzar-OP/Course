#include <iostream>
#include <stack>
using namespace std;
void smallestOnLeft(vector<int> vec)
{
    int n = vec.size();
    stack<int> st;
    vector<int> ans(n, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && vec[st.top()] > vec[i])
        {
            ans[st.top()] = vec[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    vector<int> vec = {4, 13, 11, 5, 9, 7, 8, 6};
    smallestOnLeft(vec);
    return 0;
}