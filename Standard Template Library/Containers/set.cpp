#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int , greater<int>>  s;
    set<int>  s2;
    // stores unique elements in sorted order

    s.insert(100);
    s.insert(10);
    s.insert(1);
    s.insert(1000);
    s.insert(100000);
    s.insert(10000);

    s2.insert(100);
    s2.insert(10);
    s2.insert(1);
    s2.insert(1000);
    s2.insert(100000);
    s2.insert(10000);

    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";

    for (auto i = s2.begin(); i != s2.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";

    set<int> s0;

    s0.insert(1);
    // s0.insert(2);
    s0.insert(3);
    // s0.insert(4);
    s0.insert(5);
    // s0.insert(6);
    s0.insert(7);
    // s0.insert(8);
    s0.insert(9);
    // s0.insert(10);

    for (auto i = s0.begin(); i != s0.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";

    cout << "*s0.lower_bound(0)" << " " << *s0.lower_bound(0) << endl;
    cout << "*s0.upper_bound(0)" << " " << *s0.upper_bound(0) << endl;
    cout << "*s0.lower_bound(1)" << " " << *s0.lower_bound(1) << endl;
    cout << "*s0.upper_bound(1)" << " " << *s0.upper_bound(1) << endl;
    cout << "*s0.lower_bound(2)" << " " << *s0.lower_bound(2) << endl;
    cout << "*s0.upper_bound(2)" << " " << *s0.upper_bound(2) << endl;
    cout << "*s0.lower_bound(3)" << " " << *s0.lower_bound(3) << endl;
    cout << "*s0.upper_bound(3)" << " " << *s0.upper_bound(3) << endl;
    cout << "*s0.lower_bound(9)" << " " << *s0.lower_bound(9) << endl;
    cout << "*s0.upper_bound(9)" << " " << *s0.upper_bound(9) << endl;
    cout << "*s0.lower_bound(19)" << " " << *s0.lower_bound(19) << endl;
    cout << "*s0.upper_bound(19)" << " " << *s0.upper_bound(19) << endl;

    return 0;
}
