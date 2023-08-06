#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l1 = {1, 5, 6};
    list<int> l2 = {2, 3, 4};

    l1.splice(++l1.begin(), move(l2));

    for (auto i : l1)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
