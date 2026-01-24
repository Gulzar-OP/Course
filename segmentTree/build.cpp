#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    int n;

    void build(int arr[], int start, int end, int node)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, start, mid, 2 * node + 1);
            build(arr, mid + 1, end, 2 * node + 2);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // sum
        }
    }
    int rangeSum(int qi, int qj, int si, int sj, int node)
    {
        if (qj < si || qi > sj)
        { // no overlap
            return 0;
        }
        if (si >= qi && sj <= qj)
        { // complete overlap
            return tree[node];
        }
        // partial overlap
        int mid = (si + sj) / 2;
        return rangeSum(qi, qj, si, mid, 2 * node + 1) + rangeSum(qi, qj, mid + 1, sj, 2 * node + 2);
    }
    void updateUtil(int idx, int newVal, int start, int end, int node)
    {
        if (start == end)
        {
            tree[node] = newVal;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
        { // left
            updateUtil(idx, newVal, start, mid, 2 * node + 1);
        }
        else
        { // right
            updateUtil(idx, newVal, mid + 1, end, 2 * node + 2);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    SegmentTree(int arr[], int size)
    {
        n = size;
        tree.resize(4 * n);
        build(arr, 0, n - 1, 0);
    }

    void printTree()
    {
        for (int i = 0; i < tree.size(); i++)
        {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
    int rangeQuery(int qi, int qj)
    {
        return rangeSum(qi, qj, 0, n - 1, 0);
    }
    void update(int idx, int value)
    {
        updateUtil(idx, value, 0, n - 1, 0);
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree st(arr, sizeof(arr) / sizeof(arr[0]));
    cout << st.rangeQuery(2, 5) << endl; // Output: 18 (3+4+5+6)
    cout << st.rangeQuery(0, 3) << endl; // Output: 10 (1+2+3+4)
    cout << st.rangeQuery(6, 7) << endl; // Output: 15 (7+8)

    st.update(1, 3);
    cout << st.rangeQuery(0, 3) << endl; // Output: 11 (1+3+3+4)

    return 0;
}