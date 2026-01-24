#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Next Smaller to Right
vector<int> NSR(vector<int> &vec)
{
    int n = vec.size();
    vector<int> ans(n, n); // agar right me koi smaller na mile to n
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && vec[st.top()] >= vec[i])
        {
            st.pop();
        }
        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// Next Smaller to Left
vector<int> NSL(vector<int> &vec)
{
    int n = vec.size();
    vector<int> ans(n, -1); // agar left me koi smaller na mile to -1
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && vec[st.top()] >= vec[i])
        {
            st.pop();
        }
        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// Largest Rectangle in Histogram
void LRectangle(vector<int> &vec)
{
    int n = vec.size();
    vector<int> left = NSL(vec);
    vector<int> right = NSR(vec);

    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int width = right[i] - left[i] - 1;
        int area = vec[i] * width;
        maxArea = max(maxArea, area);
    }
    cout << "Largest Rectangle Area = " << maxArea << endl;
}

int main()
{
    vector<int> vec = {4, 13, 11, 5, 9, 7, 8, 6};
    LRectangle(vec);
    return 0;
}
