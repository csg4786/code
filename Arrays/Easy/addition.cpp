#include <bits/stdc++.h>
using namespace std;

vector<int> addition(vector<int> a, int n, vector<int> b, int m) {
    int i = n - 1, j = m - 1, carry = 0;

    vector<int> ans(max(n, m));
    int ind = max(m,n) - 1;
    while (i >= 0 and j >= 0)
    {
        // cout << i << " " << j << " " << ind << " " << ans[ind] << endl;
        ans[ind--] = (carry + a[i] + b[j]) % 10;
        carry = (carry + a[i--] + b[j--]) / 10;

    }

    while (i >= 0)
    {
        // cout << i << " " << j << " " << ind << " " << ans[ind] << endl;
        ans[ind--] = (carry + a[i]) % 10;
        carry = (carry + a[i--]) / 10;
    }

    while (j >= 0)
    {
        // cout << i << " " << j << " " << ind << " " << ans[ind] << endl;
        ans[ind--] = (carry + b[j]) % 10;
        carry = (carry + b[j--]) / 10;
    }

    while (carry > 0)
    {
        // cout << i << " " << j << " " << ind << " " << ans[ind] << endl;
        ans.insert(ans.begin(), carry % 10);
        carry /= 10;
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    for (auto i : addition(a, n, b, m))
    {
        cout << i << " ";
    }
    cout << "\n";
    

    return 0;
}
