#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class disjointSet
{
public:
    int n;
    vector<int> parent;
    vector<int> rank;

    disjointSet(int n)
    {
        this->n = n;
        parent.resize(n); // FIXED: resize karna zaroori hai
        rank.resize(n);   // FIXED: resize karna zaroori hai
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;                       
        return parent[x] = find(parent[x]); // Path compression
    }

    void unionSet(int x, int y)
    {
        int parA = find(x);
        int parB = find(y);
        if (parA == parB)
            return;
        // Union by rank
        if (rank[parA] < rank[parB])
            parent[parA] = parB;
        else if (rank[parA] > rank[parB])
            parent[parB] = parA;
        else
        {
            parent[parB] = parA;
            rank[parA]++;
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Parent of " << i << " is " << parent[i] << " and rank is " << rank[i] << endl;
        }
    }
};

int main()
{
    disjointSet ds(6); // 5 elements: 0 to 4

    ds.unionSet(0, 2); // 0 aur 1 ko ek group me karo
    cout << ds.find(2) << endl;
    ds.unionSet(1, 3);          // 1 aur 2 ko ek group me karo
    ds.unionSet(2, 5);          // 3 aur 4 ko ek group me karo
    cout << ds.find(2) << endl; // 0 ka parent kya hai
    ds.unionSet(0, 3);          // 2 aur 3 ko ek group me karo (ab 0-1-2-3-4 ek hi group me honge) // 1 aur 4 ko ek group me karo
    ds.unionSet(0, 4);

    ds.print();
    return 0;
}
