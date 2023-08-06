#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << __builtin_popcount(n);

    long long m;
    cin >> m;
    cout << __builtin_popcountll(m);
    return 0;
}
