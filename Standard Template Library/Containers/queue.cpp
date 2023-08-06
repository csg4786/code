#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue <int> q;

    // FIFO PRINCIPLE

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();

    cout << q.empty();

    return 0;
}