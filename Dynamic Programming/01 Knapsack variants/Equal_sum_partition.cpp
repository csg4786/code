#include <bits/stdc++.h>
using namespace std;

int dp1[1002][1002];

bool equal_sum(int arr[], int n, int k)
{
    if (k == 0)
    {
        return true;
    }
    else if (n == 0)
    {
        return false;
    }
    if (k >= arr[n - 1])
    {
        return equal_sum(arr, n - 1, k - arr[n - 1]) || equal_sum(arr, n - 1, k);
    }
    else
    {
        return equal_sum(arr, n - 1, k);
    }
}

bool equal_sum_with_memoization(int arr[], int n, int k)
{
    if (k == 0)
    {
        return true;
    }
    else if (n == 0)
    {
        return false;
    }
    if (k >= arr[n - 1])
    {
        if (dp1[n][k] != -1)
            return dp1[n][k];
        else
            return dp1[n][k] = equal_sum(arr, n - 1, k - arr[n - 1]) || equal_sum(arr, n - 1, k);
    }
    else
    {
        return dp1[n][k] = equal_sum(arr, n - 1, k);
    }
}

bool equal_sum_with_tabulation(int arr[], int n, int k)
{

    bool dp2[n + 1][k + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            if (j == 0)
                dp2[i][j] = true;
            else
                dp2[i][j] = false;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            if (j >= arr[i - 1])
                dp2[i][j] = (dp2[i - 1][j - arr[i - 1]] || dp2[i - 1][j]);
            else
                dp2[i][j] = dp2[i - 1][j];
        }
    }

    return dp2[n][k];
}

int main()
{
    memset(dp1, -1, sizeof(dp1));

    int n;
    cin >> n;

    long int sum = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    
    if (sum%2) cout << "No\n";
    else {
    //    equal_sum(arr, n, sum/2) ? cout << "Yes\n" : cout << "No\n";
    //    equal_sum_with_memoization(arr, n, sum/2) ? cout << "Yes\n" : cout << "No\n";
       equal_sum_with_tabulation(arr, n, sum/2) ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}
