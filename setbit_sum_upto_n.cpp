#include <bits/stdc++.h>
using namespace std;

long long fun(long long n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    long long a = n - (long long)(pow(2, (long long)log2(n))) + 1;
    return a + ((long long)(pow(2, (long long)log2(n) - 1)) * (long long)log2(n)) + fun(a - 1);
}

int main()
{
    long long n;
    cin >> n;

    for (int i = 0; i < n + 1; i++)
    {
        cout << fun(i) << endl;
    }
    // cout << fun(n) << endl;

    return 0;
}
