#include <iostream>
#include <stack>
using namespace std;
void nextGreaterCircular(vector<int> vec)
{
    int n = vec.size();
    stack<int> st;
    vector<int> ans(n, -1);

    for (int i = 0;i<n*2 -1;i++)
    {
        while (!st.empty() && vec[st.top()] < vec[i%n])
        {
            ans[st.top()] = vec[i%n];
            st.pop();
        }
        st.push(i%n);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    vector<int> vec = {6,10,7,4,8,9,4};
    nextGreaterCircular(vec);
    return 0;
}