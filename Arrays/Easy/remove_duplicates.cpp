#include <bits/stdc++.h>
using namespace std;

int remove_duplicate(int a[],int n){
   int x =0;
    for (int i = 1; i < n; i++){
        cout << x << " " << i << endl;
        if (a[x] != a[i]){
            x++;
            a[x] = a[i];
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
    }
    return x+1;
}

int main()
{
    int n;
    cin >> n;

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

    cout << remove_duplicate(a, n) << endl;

    int c = remove_duplicate(a, n);

    for (int i = 0; i < c; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
// 42
// 1 3 4 5 6 12 13 17 19 22 23 25 27 28 28 35 36 37 39 43 46 48 54 59 62 63 65 68 68 70 70 72 79 82 83 92 92 93 95 96 96 100