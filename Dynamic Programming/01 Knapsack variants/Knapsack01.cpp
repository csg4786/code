#include <bits/stdc++.h>
using namespace std;

int dp1[1002][1002];

// int c1, c2, c3;

int knapsack_with_memoization(int arr[], int brr[], int n, int w)
{
    // c2++;
    if (n == 0 or w == 0)
        return 0;
    if (w >= arr[n - 1])
    {
        if (dp1[n][w] != -1)
        {
            return dp1[n][w];
        }
        return dp1[n][w] = max(brr[n - 1] + knapsack_with_memoization(arr, brr, n - 1, w - arr[n - 1]), knapsack_with_memoization(arr, brr, n - 1, w));
    }
    else
    {
        return dp1[n][w] = knapsack_with_memoization(arr, brr, n - 1, w);
    }
}

int knapsack_with_tabulation(int arr[], int brr[], int n, int w){
    int dp2[n+1][w+1] = {0};
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if (i == 0 or j == 0) dp2[i][j] = 0;
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
            // c3++;   
            if (j >= arr[i-1])
                dp2[i][j] = max(brr[i-1]+dp2[i-1][j-arr[i-1]], dp2[i-1][j]);
            else
                dp2[i][j] = dp2[i-1][j];
        }
    }
    return dp2[n][w];
}

int knapsack(int arr[], int brr[], int n, int w)
{
    // c1++;
    if (n == 0 or w == 0)
        return 0;
    if (w >= arr[n - 1])
        return max(brr[n - 1] + knapsack(arr, brr, n - 1, w - arr[n - 1]), knapsack(arr, brr, n - 1, w));
    else
        return knapsack(arr, brr, n - 1, w);
}

int main()
{
    int n, w;
    cin >> n >> w;

    memset(dp1, -1, sizeof(dp1));

    int arr[n], brr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
    }

    // cout << knapsack(arr, brr, n, w) << "\n";
    // cout << knapsack_with_memoization(arr, brr, n, w) << "\n";
    cout << knapsack_with_tabulation(arr, brr, n, w) << "\n";

    // cout << c1 << " " << c2 << " " << c3 << "\n";

    return 0;
}
