#include <bits/stdc++.h>
using namespace std;

void insrt(int arr[], int s, int e) {
    if (s == e or arr[e] >= arr[e-1]){
        return;
    }
    else {
        swap(arr[e-1], arr[e]);
        insrt(arr, s, e-1);
    }
}

void sort_arr(int arr[], int s, int e){

    if (s == e){
        return;
    }

    sort_arr(arr, s, e-1);
    insrt(arr, s, e);
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

    sort_arr(arr, 0, n-1);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}