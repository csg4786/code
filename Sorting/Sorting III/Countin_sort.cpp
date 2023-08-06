#include <bits/stdc++.h>
using namespace std;

void counting_sort(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (mx < arr[i]){
            mx = arr[i];
        }
    }
    mx++;

    int freq[mx] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    
    for (int i = 1; i < mx; i++)
    {
        freq[i] += freq[i-1];
    }
    
    int final_arr[n];
    for (int i = 0; i < n; i++)
    {
        final_arr[freq[arr[i]]-1] = arr[i];
        freq[arr[i]]--;
    }
    
    for (int i = 0; i < n; i++)
    {
       arr[i] = final_arr[i];
    }
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

    counting_sort(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
