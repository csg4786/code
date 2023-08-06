#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> v;

    // for (int i = 0; i < 20; i += 2)
    // {
    //     if (i != 10)
    //     {
    //         v.push_back(i);
    //     }
    // }

    // for (auto &&i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // auto it = v.begin() + 5;
    // v.insert(it, 10);
    // for (auto &&i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // cout << v.back() << endl;
    // cout << v.front() << endl;

    // v.erase(v.begin());
    // v.pop_back();

    // cout << v.back() << endl;
    // cout << v.front() << endl;

    vector<int> v(5,20), v2(v);
    v2.push_back(10); 
    v2.push_back(100); 
    v2.push_back(1000); 

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;

    // v2.erase(v2.begin(), v2.end()-1);
    pair<vector<int>::iterator, vector<int>::iterator> p = minmax_element(v2.begin(),v2.end());

    cout << *p.first << " " << *p.second <<  endl;
    
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}