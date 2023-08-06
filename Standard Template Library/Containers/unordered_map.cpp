#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, int> m;

    string name;
    cin >> name;

    for (int i = 0; i < name.length(); i++)
    {
        m[name[i]]++;
    }
    
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
