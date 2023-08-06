#include <bits/stdc++.h>
using namespace std;

int longest_sum_k(vector<int> arr, int n, int k){
    // // vector<int> b;
    // int n = a.size();
    // int i = 0, j = -1, sum = 0, max_length = 0;
    // while (i < n){
    //     while (j < n - 1 and a[j+1]+sum <= k){
    //         sum += a[j++];
    //         // b.push_back(a[j]);
    //     }
    //     if (sum == k){
    //         max_length = max(max_length, (j-i+1));
    //     }

    //     sum -= a[i];
    //     // b.erase(b.begin());
    //     i++;
    // }
    // // return b;
    // // for (auto &&i : b)
    // // {
    // //     cout << i << " ";
    // // }
    // return max_length;

    int start = 0, end = -1, sum = 0, maxLength = 0;
    while (start < n)
    {
        while ((end + 1 < n) && (sum + arr[end + 1] <= k))
            sum += arr[++end];

        if (sum == k)
            maxLength = max(maxLength, (end - start + 1));

        sum -= arr[start];
        start++;
    }
    return maxLength;
}

int main()
{
    int n, k;
    cin>>n>>k;

    vector<int> a(n), b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // b = longest_sum_k(a, k);
    cout << longest_sum_k(a, n, k);

    // for (auto &&i : b)
    // {
    //     cout << i << " ";
    // }

    return 0;
}
