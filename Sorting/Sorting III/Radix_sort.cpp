#include <bits/stdc++.h>
using namespace std;

void counting_sort(int arr[], int n, int j){

    int freq[10] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[(arr[i]/((int)(pow(10,j))))%10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        freq[i] += freq[i-1];
    }

    int final_arr[n];
    for (int i = n-1; i >= 0; i--)
    {
        final_arr[freq[(arr[i] / ((int)(pow(10, j)))) % 10] - 1] = arr[i];
        freq[(arr[i] / ((int)(pow(10, j)))) % 10]--;
    }
    
    for (int i = 0; i < n; i++)
    {
       arr[i] = final_arr[i];
    }
}

void radix_sort(int arr[], int n){
    int places = 0;
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
       if (mx < arr[i])
       {
           mx = arr[i];
       }
    }
    while (mx)
    {
        mx /= 10;
        places++;
    }
    for (int i = 0; i < places; i++)
    {
        counting_sort(arr, n, i);
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
    
    radix_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
