// #include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    unordered_set<int> us;

    // unique elements but not sorted

    vector<int> v;

    for (int i = 2; i < 20; i += 2)
    {
        us.insert(i);
        us.insert(i - 1);
    }

    for (auto &&i : us)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << us.size() << endl;

    us.erase(us.find(10));
    us.erase(us.find(11));

    for (auto &&i : us)
    {
        v.push_back(i);
        cout << i << " ";
    }
    cout << endl;

    // sort(us.begin(), us.end());           sort does not work for unordered set and it need not work for ordered set.
    // for (auto &&i : us)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    sort(v.begin(), v.end());
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << us.size() << endl;

    us.clear();
    cout << us.size() << endl;
    (us.empty()) ? cout << "Empty\n" : cout << "Not Empty\n";

    return 0;
}
