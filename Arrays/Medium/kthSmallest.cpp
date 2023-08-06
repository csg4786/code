#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r){
    int i = l, j = l-1;
    
    while (i < r+1){
        if (arr[i] <= arr[r]){
            j++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        i++;
    }
    
    return j;
}

int kthSmallest(int arr[], int l, int r, int k) {
    int k1 = partition(arr, l, r);
    // cout << l << " " << k1 << " " << r << endl;
    
    if (k1 == k-1){
        return arr[k-1];
    }
    else if (k1 < k-1){
        return kthSmallest(arr, k1+1, r, k);
    }
    else return kthSmallest(arr, l, k1-1, k);
}

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << kthSmallest(arr, 0, n-1, k) << endl;

    return 0;
}
