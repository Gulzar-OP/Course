#include <iostream>
#include <queue>
using namespace std;

queue<int> q1;
queue<int> q2;

void push(int x)
{
    q1.push(x);

    // q2 ke sabhi elements q1 me daalo
    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }

    // ab q1 ke sabhi elements q2 me daalo
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
}

void display()
{
    queue<int> temp = q2; // q2 me stack order hai
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        push(arr[i]);
    }
    display();
    return 0;
}