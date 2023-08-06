#include <bits/stdc++.h>
using namespace std;

int min_subset_sum_diff(int arr[], int n)
{

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int dp[n + 1][sum/2 + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum/2 + 1; j++)
            if (j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum/2 + 1; j++)
        {
            if (j >= arr[i - 1])
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int s1 = 0;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i])
        {
            s1 = i;
            break;
        }
    }

    return sum-2*s1; 
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << min_subset_sum_diff(arr, n) << "\n";

    return 0;
}
