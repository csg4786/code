#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll val1 = 1;
    ll vl1 = 1;
    int sum1 = 0;

    for (int i = 0; i < n; i++)
    {
        // cout << "1. "<< val1 << "\n";
        val1 *= a[i];
        sum1 += a[i];
        vl1 *= (a[i] - 1) ? (a[i] - 1) : 1;
        // cout << "2. " << val1 << "\n";
    }

    ll val2 = 1;
    ll vl2 = 1;
    int sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        // cout << "3. " << val2 << "\n";
        val2 *= b[i];
        sum2 += b[i];
        vl2 *= (b[i] - 1) ? (b[i] - 1) : 1;
        // cout << "4. " << val2 << "\n";
    }

    // cout << "5. " << val << "\n";
    ((val1 == val2 && sum1 == sum2 && vl1 == vl2) ? cout << "Yes" : cout << "No");

    return 0;
}
