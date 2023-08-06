#include <bits/stdc++.h>
using namespace std;

int dpmemo[1001][1001];

int coin_change2 (int denoms[], int n, int k) {
    if (k == 0)
        return 0;
    if (n == 0) 
        return INT_MAX-1;
    if (k >= denoms[n-1]) {
        int take = coin_change2(denoms, n, k - denoms[n - 1]);
        int not_take = coin_change2(denoms, n-1, k);
        return min(1 + take, not_take);
    } else {
        return coin_change2(denoms, n-1, k);
    }
}

int coin_change2_memo (int denoms[], int n, int k) {
    if (k == 0)
        return 0;
    if (n == 0) 
        return INT_MAX-1;
    if (dpmemo[n][k] == -1) {
        if (k >= denoms[n-1]) {
            int take = coin_change2_memo(denoms, n, k - denoms[n - 1]);
            int not_take = coin_change2_memo(denoms, n - 1, k);
            return dpmemo[n][k] = min(1 + take, not_take);
        } else {
            return dpmemo[n][k] = coin_change2_memo(denoms, n-1, k);
        }
    } else {
        return dpmemo[n][k];
    }
}

int coin_change2_tab (int denoms[], int n, int k) {
    int dp[n+1][k+1];

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < k+1; j++)
        {
            if (j == 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = INT_MAX-1;
        }
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < k+1; j++)
        {
            if (j >= denoms[i-1]) {
                int take = dp[i][j - denoms[i - 1]];
                int not_take = dp[i - 1][j];
                dp[i][j] = min(1 + take, not_take);
            }
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
    
    // cout << coin_change2(denoms, n, k) << "\n";
    // cout << coin_change2_memo(denoms, n, k) << "\n";
    cout << coin_change2_tab(denoms, n, k) << "\n";

    return 0;
}
