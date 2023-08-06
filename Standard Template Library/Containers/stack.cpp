#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;

    // LIFO PRINCIPLE

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    cout << s.empty() << endl;

    return 0;
}