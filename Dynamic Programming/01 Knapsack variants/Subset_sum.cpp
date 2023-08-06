#include <bits/stdc++.h>
using namespace std;

int dp1[1002][1002];

bool subset_sum(int arr[], int n, int k){
    if (k == 0){
        return true;
    }
    else if (n == 0) {
        return false;
    }
    if (k >= arr[n-1]){
        return subset_sum(arr, n - 1, k - arr[n - 1]) || subset_sum(arr, n - 1, k);
    }
    else{
        return subset_sum(arr, n - 1, k);
    }
}

bool subset_sum_with_memoization(int arr[], int n, int k){
    if (k == 0){
        return true;
    }
    else if (n == 0) {
        return false;
    }
    if (k >= arr[n-1]){
        if (dp1[n][k] != -1) return dp1[n][k];
        else return dp1[n][k] = subset_sum(arr, n - 1, k - arr[n - 1]) || subset_sum(arr, n - 1, k);
    }
    else{
        return dp1[n][k] = subset_sum(arr, n - 1, k);
    }
}

bool subset_sum_with_tabulation(int arr[], int n, int k){

    bool dp2[n+1][k+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            if (j == 0) dp2[i][j] = true;
            else dp2[i][j] = false;
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            if (j >= arr[i-1]) dp2[i][j] = (dp2[i-1][j-arr[i-1]] || dp2[i-1][j]);
            else dp2[i][j] = dp2[i-1][j];
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

    // subset_sum(arr, n, k) ? cout << "Yes\n" : cout << "No\n";
    // subset_sum_with_memoization(arr, n, k) ? cout << "Yes\n" : cout << "No\n";
    subset_sum_with_tabulation(arr, n, k) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
