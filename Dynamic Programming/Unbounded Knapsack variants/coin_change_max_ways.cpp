#include <bits/stdc++.h>
using namespace std;

int dpmemo[1001][1001];

int coin_change1 (int denoms[], int n, int k) {
    if (k == 0)
        return 1;
    if (n == 0)
        return 0;
    
    if (k >= denoms[n-1]) {
        return coin_change1(denoms, n, k-denoms[n-1]) + coin_change1(denoms, n-1, k);
    } else {
        return coin_change1(denoms, n-1, k);
    }
}

int coin_change1_memo (int denoms[], int n, int k) {
    if (k == 0)
        return 1;
    if (n == 0)
        return 0;
    if (dpmemo[n][k] == -1) {
        if (k >= denoms[n-1]) {
            return dpmemo[n][k] = coin_change1_memo(denoms, n, k-denoms[n-1]) + coin_change1_memo(denoms, n-1, k);
        } else {
            return dpmemo[n][k] = coin_change1_memo(denoms, n-1, k);
        }
    } else {
        return dpmemo[n][k];
    }
}

int coin_change1_tab (int denoms[], int n, int k) {
    int dp[n+1][k+1];

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < k+1; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < k+1; j++)
        {
            if (j >= denoms[i-1])
                dp[i][j] = dp[i][j-denoms[i-1]]+dp[i-1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    
    return dp[n][k];
}

int main()
{
    memset(dpmemo, -1, sizeof(dpmemo));

    int n, k;
    cin >> n >> k;

    int denoms[n];

    for (int i = 0; i < n; i++) {
        cin >> denoms[i];
    }
    
    // cout << coin_change1(denoms, n, k) << "\n";
    // cout << coin_change1_memo(denoms, n, k) << "\n";
    cout << coin_change1_tab(denoms, n, k) << "\n";

    return 0;
}
