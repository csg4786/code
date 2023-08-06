#include <bits/stdc++.h>
using namespace std;

int main()
{
    multimap<char, int> m;

    string name;
    cin >> name;

    for (int i = 0; i < name.length(); i++)
    {
        m.insert({name[i],name[i]-'a'+1});
    }
    
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
