#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class student
{
public:
    string name;
    int marks;

    student(string name, int marks)
    {
        this->name = name;
        this->marks = marks;
    }
    bool operator<(const student &obj) const
    {
        return this->marks < obj.marks;
    }
};

int main()
{
    priority_queue<student> pq;
    pq.push(student{"gulzar", 90});
    pq.push(student{"kadir", 95});
    pq.push(student{"ahmad", 80});

    while (!pq.empty())
    {
        cout << "top: " << pq.top().name << " , " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}