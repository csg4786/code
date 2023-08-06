#include <bits/stdc++.h>
using namespace std;

int dp1[1002][1002];

int count_subset_sum(int arr[], int n, int k)
{
    if (k == 0)
        return 1;
    if (n == 0)
        return 0;

    if (k >= arr[n - 1])
        return count_subset_sum(arr, n - 1, k - arr[n - 1]) + count_subset_sum(arr, n - 1, k);
    else
        return count_subset_sum(arr, n - 1, k);
}

int count_subset_sum_with_memoization(int arr[], int n, int k)
{
    if (n == 0 and k != 0)
        return 0;
    if (k == 0)
        return 1;

    if (k >= arr[n - 1])
    {
        if (dp1[n][k] != -1)
            return dp1[n][k];
        else
            return dp1[n][k] = count_subset_sum_with_memoization(arr, n - 1, k - arr[n - 1]) + count_subset_sum_with_memoization(arr, n - 1, k);
    }
    else
        return dp1[n][k] = count_subset_sum_with_memoization(arr, n - 1, k);
}

int count_subset_sum_with_tabulation(int arr[], int n, int k)
{

    int dp2[n + 1][k + 1] = {0};

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            if (j == 0)
                dp2[i][j] = 1;
            else
                dp2[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            if (j >= arr[i - 1])
                dp2[i][j] = (dp2[i - 1][j - arr[i - 1]] + dp2[i - 1][j]);
            else
                dp2[i][j] = dp2[i - 1][j];
        }
    }

    return dp2[n][k];
}

int main()
{
    memset(dp1, -1, sizeof(dp1));

    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << count_subset_sum(arr, n, k) << "\n";
    // cout << count_subset_sum_with_memoization(arr, n, k) << "\n";
    cout << count_subset_sum_with_tabulation(arr, n, k) << "\n";

    return 0;
}