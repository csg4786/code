#include <bits/stdc++.h>
using namespace std;

int count_subset_of_given_diff(int arr[], int n, int d) {

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    int s1 = (sum-d)/2;
    int dp[n+1][s1+1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < s1 + 1; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < s1 + 1; j++)
        {
            if (j >= arr[i-1])
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][s1];
}

int main()
{
    int n, d;
    cin >> n >> d;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << count_subset_of_given_diff(arr, n, d) <<"\n";

    return 0;
}