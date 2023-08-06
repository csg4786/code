#include <bits/stdc++.h>
using namespace std;

int dpmemo[1001][1001];

int rod_cutting(int length[], int price[], int n, int k) {
    if (n == 0) {
        return 0;
    }

    if (k >= length[n-1]) {
        return max(price[n-1] + rod_cutting(length, price, n, k - length[n - 1]), rod_cutting(length, price, n - 1, k));
    }
    else {
        return rod_cutting(length, price, n-1, k);
    }
}

int rod_cutting_memo(int length[], int price[], int n, int k) {
    if (n == 0) {
        return 0;
    }

    if (dpmemo[n][k] == -1) {

        if (k >= length[n-1]) {
            return dpmemo[n][k] = max(price[n-1] + rod_cutting_memo(length, price, n, k - length[n - 1]), rod_cutting_memo(length, price, n - 1, k));
        }
        else {
            return dpmemo[n][k] = rod_cutting_memo(length, price, n - 1, k);
        }
    } else {
        return dpmemo[n][k];
    }
}

int rod_cutting_tab(int length[], int price[], int n) {
    
    int dp[n+1][n+1];

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (j >= length[i-1])
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][n];
}

int main()
{
    memset(dpmemo, -1, sizeof(dpmemo));

    int n;
    cin >> n;

    int length[n], price[n];

    for (int i = 0; i < n; i++) {
        cin >> length[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    
    // cout << rod_cutting(length, price, n, n) << "\n";
    // cout << rod_cutting_memo(length, price, n, n) << "\n";
    cout << rod_cutting_tab(length, price, n) << "\n";

    return 0;
}
