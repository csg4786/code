#include <bits/stdc++.h>
using namespace std;

long long smallest_no_sum(vector<long long> arr, int n){
    long long ans = 1;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (ans < arr[i]){
            return ans;
        }
        else{
            ans += arr[i];
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << smallest_no_sum(arr, n);

    return 0;
}