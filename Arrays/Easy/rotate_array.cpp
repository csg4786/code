#include <bits/stdc++.h>
using namespace std;

void rotateK(int a[], int k, int n)
{
    k = k%n;
    if (k > 0)
    {
        for (int i = 0; i < k / 2; i++)
        {
            swap(a[i], a[k - i - 1]);
        }
        for (int i = 0; i < (n - k) / 2; i++)
        {
            swap(a[i + k], a[n - i - 1]);
        }
        for (int i = 0; i < n / 2; i++)
        {
            swap(a[i], a[n - i - 1]);
        }
    }
}

// void rotateK(int a[], int k, int n){
//     for (int i = 0; i < n - k; i++)
//     {
//         swap(a[i],a[i+k]);
//     }
//     for (int i = 0; i < n%k; i++)
//     {
//         swap(a[n-k+(i+(n%k))%k],a[n-k+i]);
//     }
// }

int main()
{
    int n, k;
    cin >> n >> k;

    // vector<int> nums(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> nums[i];
    // }

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    rotateK(a, k, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
