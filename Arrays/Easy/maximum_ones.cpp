#include <bits/stdc++.h>
using namespace std;

// int findZeroes(int a[], int n, int m)
// {
    // int i = 0, j = 0, mx = 0, k = 0;
    // while (j < n)
    // {
    //     if (a[j] == 0)
    //     {
    //         k++;
    //     }
    //     if (k > m)
    //     {
    //         if (a[i] == 0)
    //         {
    //             k--;
    //         }
    //         i++;
    //     }
    //     else
    //     {
    //         mx = max(mx, (j - i + 1));
    //     }
    //     j++;
    // }
    // return mx;

    int findMaxConsecutiveOnes(int nums[], int n)
    {
        int i = 0, j = 0, mx = 0;
        // int n = nums.size();
        while (j < n)
        {
            if (nums[j] == 0)
            {
                int k = j;
                while (nums[k] == 0)
                {
                    k++;
                }
                i = k;
            }
            else
            {
                mx = max(mx, (j - i + 1));
            }
            j++;
        }
        return mx;
    }
// }

int main()
{
    int n, m;
    cin >> n >> m;


    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    // cout << findZeroes(a, n, m) << endl;
    cout << findMaxConsecutiveOnes(a, n) << endl;

    return 0;
}

